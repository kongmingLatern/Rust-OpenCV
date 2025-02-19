use std::ffi::{c_void, CString};
use std::os::raw::c_char;

use crate::Result;

/// Common trait of all OpenCV related types, helps with generic handling of FFI marshalling
///
/// This trait is somewhat unnecessary complex because of the need of handling String, we need to be able to
/// pass &str as argument to functions that await String and do necessary conversion through CString.
#[doc(hidden)]
pub trait OpenCVType<'a>: Sized + OpenCVTypeArg<'a> {
	/// Type when passed as argument to function, e.g. &str for String, for most other types it's Self
	#[doc(hidden)]
	type Arg: OpenCVTypeArg<'a>;
	/// Return type when this type is returned over the FFI boundary from the C++ function, Self for simple
	/// types, *mut c_void for complex ones
	#[doc(hidden)]
	type ExternReceive;

	/// Construct the new Self from the data received from C++ function
	#[doc(hidden)]
	unsafe fn opencv_from_extern(s: Self::ExternReceive) -> Self;
}

/// Common trait for types that can be used as argument that will be converted into a OpenCV type.
///
/// Mostly necessary to be able to pass `&str` argument for types that otherwise have `String` Rust representation.
#[doc(hidden)]
pub trait OpenCVTypeArg<'a>: Sized {
	/// Container to help marshall type over FFI boundary, e.g. CString for String or &str, for most other
	/// types it's Self
	#[doc(hidden)]
	type ExternContainer: OpenCVTypeExternContainer<'a>;

	/// Convert Self into external container with possible error result, it shouldn't panic
	#[doc(hidden)]
	#[inline]
	fn opencv_into_extern_container(self) -> Result<Self::ExternContainer> {
		Ok(self.opencv_into_extern_container_nofail())
	}
	/// Convert Self into external container in the nofail context, this can panic
	#[doc(hidden)]
	fn opencv_into_extern_container_nofail(self) -> Self::ExternContainer;
}

/// Common trait for the type that is used to help marshall OpenCV related type over the FFI boundary
#[doc(hidden)]
pub trait OpenCVTypeExternContainer<'a> {
	/// Type when constant Self is sent to C++ function, usually it's Self for simple types or *const c_void
	/// for complex ones
	#[doc(hidden)]
	type ExternSend;
	/// Type when mutable Self is sent to C++ function, usually it's Self for simple types or *mut c_void for
	/// complex ones
	#[doc(hidden)]
	type ExternSendMut;

	#[doc(hidden)]
	fn opencv_as_extern(&self) -> Self::ExternSend;
	#[doc(hidden)]
	fn opencv_as_extern_mut(&mut self) -> Self::ExternSendMut;
	#[doc(hidden)]
	fn opencv_into_extern(self) -> Self::ExternSendMut;
}

/// Extern type to receive the OpenCVType over FFI boundary, used to improve readability
#[macro_export]
macro_rules! extern_receive {
	($typ: ty) => {
		extern_receive!($typ: '_)
	};
	($typ: ty: $lt: lifetime) => {
		<$typ as $crate::traits::OpenCVType<$lt>>::ExternReceive
	};
}

/// Extern type to send the OpenCVTypeExternContainer over FFI boundary, used to improve readability
#[macro_export]
macro_rules! extern_send {
	(mut $typ: ty: $lt: lifetime) => {
		<$typ as OpenCVTypeExternContainer<$lt>>::ExternSendMut
	};
	($typ: ty: $lt: lifetime) => {
		<$typ as OpenCVTypeExternContainer<$lt>>::ExternSend
	};
	(mut $typ: ty) => {
		extern_send!(mut $typ: '_)
	};
	($typ: ty) => {
		extern_send!($typ: '_)
	};
}

/// Extern type to send the owned OpenCVType over FFI boundary, used to improve readability
#[macro_export]
macro_rules! extern_container_send {
	(mut $typ: ty: $lt: lifetime) => {
		extern_send!(mut <$typ as OpenCVTypeArg<$lt>>::ExternContainer: $lt)
	};
	($typ: ty: $lt: lifetime) => {
		extern_send!(<$typ as OpenCVTypeArg<$lt>>::ExternContainer: $lt)
	};
}

/// Extern type to send the ::Arg of a OpenCVType over FFI boundary, used to improve readability
#[macro_export]
macro_rules! extern_arg_send {
	(mut $typ: ty: $lt: lifetime) => {
		extern_container_send!(mut <$typ as OpenCVType<$lt>>::Arg: $lt)
	};
	($typ: ty: $lt: lifetime) => {
		extern_container_send!(<$typ as OpenCVType<$lt>>::Arg: $lt)
	};
}

#[macro_export]
macro_rules! opencv_type_copy {
	($($type: ty),+ $(,)?) => {
		$(
			impl $crate::traits::OpenCVType<'_> for $type {
				type Arg = Self;
				type ExternReceive = Self;

				#[inline] unsafe fn opencv_from_extern(s: Self) -> Self { s }
			}

			impl $crate::traits::OpenCVTypeArg<'_> for $type {
				type ExternContainer = Self;

				#[inline] fn opencv_into_extern_container_nofail(self) -> Self { self }
			}

			impl $crate::traits::OpenCVTypeExternContainer<'_> for $type {
				type ExternSend = Self;
				type ExternSendMut = Self;

				#[inline] fn opencv_as_extern(&self) -> Self { *self }
				#[inline] fn opencv_as_extern_mut(&mut self) -> Self { *self }
				#[inline] fn opencv_into_extern(self) -> Self { self }
			}
		)+
	};
}

#[macro_export]
macro_rules! opencv_type_enum {
	($type: ty) => {
		$crate::opencv_type_copy! { $type }
	};
}

#[macro_export]
macro_rules! opencv_type_simple {
	($type: ty) => {
		impl $crate::traits::OpenCVType<'_> for $type {
			type Arg = Self;
			type ExternReceive = Self;

			#[inline]
			unsafe fn opencv_from_extern(s: Self) -> Self {
				s
			}
		}

		impl $crate::traits::OpenCVTypeArg<'_> for $type {
			type ExternContainer = Self;

			#[inline]
			fn opencv_into_extern_container_nofail(self) -> Self {
				self
			}
		}

		impl $crate::traits::OpenCVTypeExternContainer<'_> for $type {
			type ExternSend = *const Self;
			type ExternSendMut = *mut Self;

			#[inline]
			fn opencv_as_extern(&self) -> Self::ExternSend {
				self
			}
			#[inline]
			fn opencv_as_extern_mut(&mut self) -> Self::ExternSendMut {
				self
			}
			#[inline]
			fn opencv_into_extern(self) -> Self::ExternSendMut {
				&mut *std::mem::ManuallyDrop::new(self) as _
			}
		}
	};
}

#[macro_export]
macro_rules! opencv_type_simple_generic {
	($type: ident<$trait: ident $( + $more: ident)*>) => {
		impl<T: $trait$( + $more)*> $crate::traits::OpenCVType<'_> for $type<T> {
			type Arg = Self;
			type ExternReceive = Self;

			#[inline] unsafe fn opencv_from_extern(s: Self) -> Self { s }
		}

		impl<T: $trait$( + $more)*> $crate::traits::OpenCVTypeArg<'_> for $type<T> {
			type ExternContainer = Self;

			#[inline] fn opencv_into_extern_container_nofail(self) -> Self { self }
		}

		impl<T: $trait$( + $more)*> $crate::traits::OpenCVTypeExternContainer<'_> for $type<T> {
			type ExternSend = *const Self;
			type ExternSendMut = *mut Self;

			#[inline] fn opencv_as_extern(&self) -> Self::ExternSend { self }
			#[inline] fn opencv_as_extern_mut(&mut self) -> Self::ExternSendMut { self }
			#[inline] fn opencv_into_extern(self) -> Self::ExternSendMut { &mut *std::mem::ManuallyDrop::new(self) as _ }
		}
	};
}

pub fn cstring_new_nofail(bytes: impl Into<Vec<u8>>) -> CString {
	match CString::new(bytes) {
		Ok(s) => s,
		Err(e) => {
			let nul_pos = e.nul_position();
			let mut bytes = e.into_vec();
			bytes.drain(nul_pos..);
			unsafe { CString::from_vec_unchecked(bytes) }
		}
	}
}

impl<'a> OpenCVType<'a> for String {
	type Arg = &'a str;
	type ExternReceive = *mut c_void;

	#[inline]
	unsafe fn opencv_from_extern(s: Self::ExternReceive) -> Self {
		crate::templ::receive_string(s as *mut String)
	}
}

impl OpenCVTypeArg<'_> for String {
	type ExternContainer = CString;

	#[inline]
	fn opencv_into_extern_container(self) -> Result<Self::ExternContainer> {
		CString::new(self).map_err(|e| e.into())
	}

	#[inline]
	fn opencv_into_extern_container_nofail(self) -> Self::ExternContainer {
		cstring_new_nofail(self)
	}
}

impl OpenCVTypeArg<'_> for &str {
	type ExternContainer = CString;

	#[inline]
	fn opencv_into_extern_container(self) -> Result<Self::ExternContainer> {
		CString::new(self).map_err(|e| e.into())
	}

	#[inline]
	fn opencv_into_extern_container_nofail(self) -> Self::ExternContainer {
		cstring_new_nofail(self)
	}
}

impl OpenCVTypeExternContainer<'_> for CString {
	type ExternSend = *const c_char;
	type ExternSendMut = *mut c_char;

	#[inline]
	fn opencv_as_extern(&self) -> Self::ExternSend {
		self.as_ptr()
	}

	#[inline]
	fn opencv_as_extern_mut(&mut self) -> Self::ExternSendMut {
		self.as_ptr() as _ // fixme: use as_mut_ptr() when it's stabilized or cast_mut() when MSRV is 1.65
	}

	#[inline]
	fn opencv_into_extern(self) -> Self::ExternSendMut {
		unimplemented!("This is intentionally left unimplemented as there seems to be no need for it and it's difficult to implement it without leakage")
	}
}

impl OpenCVType<'_> for Vec<u8> {
	type Arg = Self;
	type ExternReceive = *mut c_void;

	#[inline]
	unsafe fn opencv_from_extern(s: Self::ExternReceive) -> Self {
		crate::templ::receive_byte_string(s as *mut Vec<u8>)
	}
}

impl OpenCVTypeArg<'_> for Vec<u8> {
	type ExternContainer = Self;

	#[inline]
	fn opencv_into_extern_container_nofail(self) -> Self::ExternContainer {
		self
	}
}

impl OpenCVTypeExternContainer<'_> for Vec<u8> {
	type ExternSend = *const u8;
	type ExternSendMut = *mut u8;

	#[inline]
	fn opencv_as_extern(&self) -> Self::ExternSend {
		self.as_ptr()
	}

	#[inline]
	fn opencv_as_extern_mut(&mut self) -> Self::ExternSendMut {
		self.as_mut_ptr()
	}

	#[inline]
	fn opencv_into_extern(self) -> Self::ExternSendMut {
		unimplemented!("This is intentionally left unimplemented as there seems to be no need for it and it's difficult to implement it without leakage")
	}
}

opencv_type_copy! {
	(),
	bool,
	i8, u8,
	i16, u16,
	i32, u32,
	i64, u64,
	f32, f64,
	isize, usize,
	*const c_void, *mut c_void,
}
