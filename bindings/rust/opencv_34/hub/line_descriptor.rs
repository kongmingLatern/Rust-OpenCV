#![allow(unused_parens)]
//! # Binary descriptors for lines extracted from an image
//! 
//! Introduction
//! ------------
//! 
//! One of the most challenging activities in computer vision is the extraction of useful information
//! from a given image. Such information, usually comes in the form of points that preserve some kind of
//! property (for instance, they are scale-invariant) and are actually representative of input image.
//! 
//! The goal of this module is seeking a new kind of representative information inside an image and
//! providing the functionalities for its extraction and representation. In particular, differently from
//! previous methods for detection of relevant elements inside an image, lines are extracted in place of
//! points; a new class is defined ad hoc to summarize a line's properties, for reuse and plotting
//! purposes.
//! 
//! Computation of binary descriptors
//! ---------------------------------
//! 
//! To obtatin a binary descriptor representing a certain line detected from a certain octave of an
//! image, we first compute a non-binary descriptor as described in [LBD](https://docs.opencv.org/3.4.10/d0/de3/citelist.html#CITEREF_LBD) . Such algorithm works on
//! lines extracted using EDLine detector, as explained in [EDL](https://docs.opencv.org/3.4.10/d0/de3/citelist.html#CITEREF_EDL) . Given a line, we consider a
//! rectangular region centered at it and called *line support region (LSR)*. Such region is divided
//! into a set of bands ![inline formula](https://latex.codecogs.com/png.latex?%5C%7BB%5F1%2C%20B%5F2%2C%20%2E%2E%2E%2C%20B%5Fm%5C%7D), whose length equals the one of line.
//! 
//! If we indicate with ![inline formula](https://latex.codecogs.com/png.latex?%5Cbf%7Bd%7D%5FL) the direction of line, the orthogonal and clockwise direction to line
//! ![inline formula](https://latex.codecogs.com/png.latex?%5Cbf%7Bd%7D%5F%7B%5Cperp%7D) can be determined; these two directions, are used to construct a reference frame
//! centered in the middle point of line. The gradients of pixels ![inline formula](https://latex.codecogs.com/png.latex?%5Cbf%7Bg%27%7D) inside LSR can be projected
//! to the newly determined frame, obtaining their local equivalent
//! ![inline formula](https://latex.codecogs.com/png.latex?%5Cbf%7Bg%27%7D%20%3D%20%28%5Cbf%7Bg%7D%5ET%20%5Ccdot%20%5Cbf%7Bd%7D%5F%7B%5Cperp%7D%2C%20%5Cbf%7Bg%7D%5ET%20%5Ccdot%20%5Cbf%7Bd%7D%5FL%29%5ET%20%5Ctriangleq%20%28%5Cbf%7Bg%27%7D%5F%7Bd%5F%7B%5Cperp%7D%7D%2C%20%5Cbf%7Bg%27%7D%5F%7Bd%5FL%7D%29%5ET).
//! 
//! Later on, a Gaussian function is applied to all LSR's pixels along ![inline formula](https://latex.codecogs.com/png.latex?%5Cbf%7Bd%7D%5F%5Cperp) direction; first,
//! we assign a global weighting coefficient ![inline formula](https://latex.codecogs.com/png.latex?f%5Fg%28i%29%20%3D%20%281%2F%5Csqrt%7B2%5Cpi%7D%5Csigma%5Fg%29e%5E%7B%2Dd%5E2%5Fi%2F2%5Csigma%5E2%5Fg%7D) to
//! *i*-th row in LSR, where ![inline formula](https://latex.codecogs.com/png.latex?d%5Fi) is the distance of *i*-th row from the center row in LSR,
//! ![inline formula](https://latex.codecogs.com/png.latex?%5Csigma%5Fg%20%3D%200%2E5%28m%20%5Ccdot%20w%20%2D%201%29) and ![inline formula](https://latex.codecogs.com/png.latex?w) is the width of bands (the same for every band). Secondly,
//! considering a band ![inline formula](https://latex.codecogs.com/png.latex?B%5Fj) and its neighbor bands ![inline formula](https://latex.codecogs.com/png.latex?B%5F%7Bj%2D1%7D%2C%20B%5F%7Bj%2B1%7D), we assign a local weighting
//! ![inline formula](https://latex.codecogs.com/png.latex?F%5Fl%28k%29%20%3D%20%281%2F%5Csqrt%7B2%5Cpi%7D%5Csigma%5Fl%29e%5E%7B%2Dd%27%5E2%5Fk%2F2%5Csigma%5Fl%5E2%7D), where ![inline formula](https://latex.codecogs.com/png.latex?d%27%5Fk) is the distance of *k*-th
//! row from the center row in ![inline formula](https://latex.codecogs.com/png.latex?B%5Fj) and ![inline formula](https://latex.codecogs.com/png.latex?%5Csigma%5Fl%20%3D%20w). Using the global and local weights, we obtain,
//! at the same time, the reduction of role played by gradients far from line and of boundary effect,
//! respectively.
//! 
//! Each band ![inline formula](https://latex.codecogs.com/png.latex?B%5Fj) in LSR has an associated *band descriptor(BD)* which is computed considering
//! previous and next band (top and bottom bands are ignored when computing descriptor for first and
//! last band). Once each band has been assignen its BD, the LBD descriptor of line is simply given by
//! 
//! ![block formula](https://latex.codecogs.com/png.latex?LBD%20%3D%20%28BD%5F1%5ET%2C%20BD%5F2%5ET%2C%20%2E%2E%2E%20%2C%20BD%5ET%5Fm%29%5ET%2E)
//! 
//! To compute a band descriptor ![inline formula](https://latex.codecogs.com/png.latex?B%5Fj), each *k*-th row in it is considered and the gradients in such
//! row are accumulated:
//! 
//! ![block formula](https://latex.codecogs.com/png.latex?%5Cbegin%7Bmatrix%7D%20%5Cbf%7BV1%7D%5Ek%5Fj%20%3D%20%5Clambda%20%5Csum%5Climits%5F%7B%5Cbf%7Bg%7D%27%5F%7Bd%5F%5Cperp%7D%3E0%7D%5Cbf%7Bg%7D%27%5F%7Bd%5F%5Cperp%7D%2C%20%26%20%20%5Cbf%7BV2%7D%5Ek%5Fj%20%3D%20%5Clambda%20%5Csum%5Climits%5F%7B%5Cbf%7Bg%7D%27%5F%7Bd%5F%5Cperp%7D%3C0%7D%20%2D%5Cbf%7Bg%7D%27%5F%7Bd%5F%5Cperp%7D%2C%20%5C%5C%20%5Cbf%7BV3%7D%5Ek%5Fj%20%3D%20%5Clambda%20%5Csum%5Climits%5F%7B%5Cbf%7Bg%7D%27%5F%7Bd%5FL%7D%3E0%7D%5Cbf%7Bg%7D%27%5F%7Bd%5FL%7D%2C%20%26%20%5Cbf%7BV4%7D%5Ek%5Fj%20%3D%20%5Clambda%20%5Csum%5Climits%5F%7B%5Cbf%7Bg%7D%27%5F%7Bd%5FL%7D%3C0%7D%20%2D%5Cbf%7Bg%7D%27%5F%7Bd%5FL%7D%5Cend%7Bmatrix%7D%2E)
//! 
//! with ![inline formula](https://latex.codecogs.com/png.latex?%5Clambda%20%3D%20f%5Fg%28k%29f%5Fl%28k%29).
//! 
//! By stacking previous results, we obtain the *band description matrix (BDM)*
//! 
//! ![block formula](https://latex.codecogs.com/png.latex?BDM%5Fj%20%3D%20%5Cleft%28%5Cbegin%7Bmatrix%7D%20%5Cbf%7BV1%7D%5Fj%5E1%20%26%20%5Cbf%7BV1%7D%5Fj%5E2%20%26%20%5Cldots%20%26%20%5Cbf%7BV1%7D%5Fj%5En%20%5C%5C%20%5Cbf%7BV2%7D%5Fj%5E1%20%26%20%5Cbf%7BV2%7D%5Fj%5E2%20%26%20%5Cldots%20%26%20%5Cbf%7BV2%7D%5Fj%5En%20%5C%5C%20%5Cbf%7BV3%7D%5Fj%5E1%20%26%20%5Cbf%7BV3%7D%5Fj%5E2%20%26%20%5Cldots%20%26%20%5Cbf%7BV3%7D%5Fj%5En%20%5C%5C%20%5Cbf%7BV4%7D%5Fj%5E1%20%26%20%5Cbf%7BV4%7D%5Fj%5E2%20%26%20%5Cldots%20%26%20%5Cbf%7BV4%7D%5Fj%5En%20%5Cend%7Bmatrix%7D%20%5Cright%29%20%5Cin%20%5Cmathbb%7BR%7D%5E%7B4%5Ctimes%20n%7D%2C)
//! 
//! with ![inline formula](https://latex.codecogs.com/png.latex?n) the number of rows in band ![inline formula](https://latex.codecogs.com/png.latex?B%5Fj):
//! 
//! ![block formula](https://latex.codecogs.com/png.latex?n%20%3D%20%5Cbegin%7Bcases%7D%202w%2C%20%26%20j%20%3D%201%7C%7Cm%3B%20%5C%5C%203w%2C%20%26%20%5Cmbox%7Belse%7D%2E%20%5Cend%7Bcases%7D)
//! 
//! Each ![inline formula](https://latex.codecogs.com/png.latex?BD%5Fj) can be obtained using the standard deviation vector ![inline formula](https://latex.codecogs.com/png.latex?S%5Fj) and mean vector ![inline formula](https://latex.codecogs.com/png.latex?M%5Fj) of
//! ![inline formula](https://latex.codecogs.com/png.latex?BDM%5FJ). Thus, finally:
//! 
//! ![block formula](https://latex.codecogs.com/png.latex?LBD%20%3D%20%28M%5F1%5ET%2C%20S%5F1%5ET%2C%20M%5F2%5ET%2C%20S%5F2%5ET%2C%20%5Cldots%2C%20M%5Fm%5ET%2C%20S%5Fm%5ET%29%5ET%20%5Cin%20%5Cmathbb%7BR%7D%5E%7B8m%7D)
//! 
//! Once the LBD has been obtained, it must be converted into a binary form. For such purpose, we
//! consider 32 possible pairs of BD inside it; each couple of BD is compared bit by bit and comparison
//! generates an 8 bit string. Concatenating 32 comparison strings, we get the 256-bit final binary
//! representation of a single LBD.
use crate::{mod_prelude::*, core, sys, types};
pub mod prelude {
	pub use { super::BinaryDescriptor_ParamsTrait, super::BinaryDescriptorTrait, super::LSDDetectorTrait, super::BinaryDescriptorMatcherTrait };
}

/// Output image matrix will be created (Mat::create),
/// i.e. existing memory of output image may be reused.
/// Two source images, matches, and single keylines
/// will be drawn.
pub const DrawLinesMatchesFlags_DEFAULT: i32 = 0;
/// Output image matrix will not be
/// created (using Mat::create). Matches will be drawn
/// on existing content of output image.
pub const DrawLinesMatchesFlags_DRAW_OVER_OUTIMG: i32 = 1;
/// Single keylines will not be drawn.
pub const DrawLinesMatchesFlags_NOT_DRAW_SINGLE_LINES: i32 = 2;
pub const MLN10: f64 = 2.30258509299404568402;
pub const RELATIVE_ERROR_FACTOR: f64 = 100.0;
pub type uint16 = u16;
pub type uint32 = u32;
pub type uint64 = u64;
pub type uint8 = u8;
/// Draws keylines.
/// 
/// ## Parameters
/// * image: input image
/// * keylines: keylines to be drawn
/// * outImage: output image to draw on
/// * color: color of lines to be drawn (if set to defaul value, color is chosen randomly)
/// * flags: drawing flags
/// 
/// ## C++ default parameters
/// * color: Scalar::all(-1)
/// * flags: DrawLinesMatchesFlags::DEFAULT
pub fn draw_keylines(image: &core::Mat, keylines: &core::Vector::<crate::line_descriptor::KeyLine>, out_image: &mut core::Mat, color: core::Scalar, flags: i32) -> Result<()> {
	unsafe { sys::cv_line_descriptor_drawKeylines_const_MatR_const_vector_KeyLine_R_MatR_const_ScalarR_int(image.as_raw_Mat(), keylines.as_raw_VectorOfKeyLine(), out_image.as_raw_mut_Mat(), &color, flags) }.into_result()
}

/// Draws the found matches of keylines from two images.
/// 
/// ## Parameters
/// * img1: first image
/// * keylines1: keylines extracted from first image
/// * img2: second image
/// * keylines2: keylines extracted from second image
/// * matches1to2: vector of matches
/// * outImg: output matrix to draw on
/// * matchColor: drawing color for matches (chosen randomly in case of default value)
/// * singleLineColor: drawing color for keylines (chosen randomly in case of default value)
/// * matchesMask: mask to indicate which matches must be drawn
/// * flags: drawing flags, see DrawLinesMatchesFlags
/// 
/// 
/// Note: If both *matchColor* and *singleLineColor* are set to their default values, function draws
/// matched lines and line connecting them with same color
/// 
/// ## C++ default parameters
/// * match_color: Scalar::all(-1)
/// * single_line_color: Scalar::all(-1)
/// * matches_mask: std::vector<char>()
/// * flags: DrawLinesMatchesFlags::DEFAULT
pub fn draw_line_matches(img1: &core::Mat, keylines1: &core::Vector::<crate::line_descriptor::KeyLine>, img2: &core::Mat, keylines2: &core::Vector::<crate::line_descriptor::KeyLine>, matches1to2: &core::Vector::<core::DMatch>, out_img: &mut core::Mat, match_color: core::Scalar, single_line_color: core::Scalar, matches_mask: &core::Vector::<i8>, flags: i32) -> Result<()> {
	unsafe { sys::cv_line_descriptor_drawLineMatches_const_MatR_const_vector_KeyLine_R_const_MatR_const_vector_KeyLine_R_const_vector_DMatch_R_MatR_const_ScalarR_const_ScalarR_const_vector_char_R_int(img1.as_raw_Mat(), keylines1.as_raw_VectorOfKeyLine(), img2.as_raw_Mat(), keylines2.as_raw_VectorOfKeyLine(), matches1to2.as_raw_VectorOfDMatch(), out_img.as_raw_mut_Mat(), &match_color, &single_line_color, matches_mask.as_raw_VectorOfi8(), flags) }.into_result()
}

/// Class implements both functionalities for detection of lines and computation of their
/// binary descriptor.
/// 
/// Class' interface is mainly based on the ones of classical detectors and extractors, such as
/// Feature2d's @ref features2d_main and @ref features2d_match. Retrieved information about lines is
/// stored in line_descriptor::KeyLine objects.
pub trait BinaryDescriptorTrait: core::AlgorithmTrait {
	fn as_raw_BinaryDescriptor(&self) -> *const c_void;
	fn as_raw_mut_BinaryDescriptor(&mut self) -> *mut c_void;

	/// Get current number of octaves
	fn get_num_of_octaves(&mut self) -> Result<i32> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_getNumOfOctaves(self.as_raw_mut_BinaryDescriptor()) }.into_result()
	}
	
	/// Set number of octaves
	/// ## Parameters
	/// * octaves: number of octaves
	fn set_num_of_octaves(&mut self, octaves: i32) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_setNumOfOctaves_int(self.as_raw_mut_BinaryDescriptor(), octaves) }.into_result()
	}
	
	/// Get current width of bands
	fn get_width_of_band(&mut self) -> Result<i32> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_getWidthOfBand(self.as_raw_mut_BinaryDescriptor()) }.into_result()
	}
	
	/// Set width of bands
	/// ## Parameters
	/// * width: width of bands
	fn set_width_of_band(&mut self, width: i32) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_setWidthOfBand_int(self.as_raw_mut_BinaryDescriptor(), width) }.into_result()
	}
	
	/// Get current reduction ratio (used in Gaussian pyramids)
	fn get_reduction_ratio(&mut self) -> Result<i32> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_getReductionRatio(self.as_raw_mut_BinaryDescriptor()) }.into_result()
	}
	
	/// Set reduction ratio (used in Gaussian pyramids)
	/// ## Parameters
	/// * rRatio: reduction ratio
	fn set_reduction_ratio(&mut self, r_ratio: i32) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_setReductionRatio_int(self.as_raw_mut_BinaryDescriptor(), r_ratio) }.into_result()
	}
	
	/// Read parameters from a FileNode object and store them
	/// 
	/// ## Parameters
	/// * fn: source FileNode file
	fn read(&mut self, fn_: &core::FileNode) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_read_const_FileNodeR(self.as_raw_mut_BinaryDescriptor(), fn_.as_raw_FileNode()) }.into_result()
	}
	
	/// Store parameters to a FileStorage object
	/// 
	/// ## Parameters
	/// * fs: output FileStorage file
	fn write(&self, fs: &mut core::FileStorage) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_write_const_FileStorageR(self.as_raw_BinaryDescriptor(), fs.as_raw_mut_FileStorage()) }.into_result()
	}
	
	/// Requires line detection
	/// 
	/// ## Parameters
	/// * image: input image
	/// * keypoints: vector that will store extracted lines for one or more images
	/// * mask: mask matrix to detect only KeyLines of interest
	/// 
	/// ## C++ default parameters
	/// * mask: Mat()
	fn detect(&mut self, image: &core::Mat, keypoints: &mut core::Vector::<crate::line_descriptor::KeyLine>, mask: &core::Mat) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_detect_const_MatR_vector_KeyLine_R_const_MatR(self.as_raw_mut_BinaryDescriptor(), image.as_raw_Mat(), keypoints.as_raw_mut_VectorOfKeyLine(), mask.as_raw_Mat()) }.into_result()
	}
	
	/// Requires line detection
	/// 
	/// ## Parameters
	/// * image: input image
	/// * keypoints: vector that will store extracted lines for one or more images
	/// * mask: mask matrix to detect only KeyLines of interest
	/// 
	/// ## Overloaded parameters
	/// 
	/// 
	/// * images: input images
	/// * keylines: set of vectors that will store extracted lines for one or more images
	/// * masks: vector of mask matrices to detect only KeyLines of interest from each input image
	/// 
	/// ## C++ default parameters
	/// * masks: std::vector<Mat>()
	fn detect_1(&self, images: &core::Vector::<core::Mat>, keylines: &mut core::Vector::<core::Vector::<crate::line_descriptor::KeyLine>>, masks: &core::Vector::<core::Mat>) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_detect_const_const_vector_Mat_R_vector_vector_KeyLine__R_const_vector_Mat_R(self.as_raw_BinaryDescriptor(), images.as_raw_VectorOfMat(), keylines.as_raw_mut_VectorOfVectorOfKeyLine(), masks.as_raw_VectorOfMat()) }.into_result()
	}
	
	/// Requires descriptors computation
	/// 
	/// ## Parameters
	/// * image: input image
	/// * keylines: vector containing lines for which descriptors must be computed
	/// * descriptors: 
	/// * returnFloatDescr: flag (when set to true, original non-binary descriptors are returned)
	/// 
	/// ## C++ default parameters
	/// * return_float_descr: false
	fn compute(&self, image: &core::Mat, keylines: &mut core::Vector::<crate::line_descriptor::KeyLine>, descriptors: &mut core::Mat, return_float_descr: bool) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_compute_const_const_MatR_vector_KeyLine_R_MatR_bool(self.as_raw_BinaryDescriptor(), image.as_raw_Mat(), keylines.as_raw_mut_VectorOfKeyLine(), descriptors.as_raw_mut_Mat(), return_float_descr) }.into_result()
	}
	
	/// Requires descriptors computation
	/// 
	/// ## Parameters
	/// * image: input image
	/// * keylines: vector containing lines for which descriptors must be computed
	/// * descriptors: 
	/// * returnFloatDescr: flag (when set to true, original non-binary descriptors are returned)
	/// 
	/// ## Overloaded parameters
	/// 
	/// 
	/// * images: input images
	/// * keylines: set of vectors containing lines for which descriptors must be computed
	/// * descriptors: 
	/// * returnFloatDescr: flag (when set to true, original non-binary descriptors are returned)
	/// 
	/// ## C++ default parameters
	/// * return_float_descr: false
	fn compute_1(&self, images: &core::Vector::<core::Mat>, keylines: &mut core::Vector::<core::Vector::<crate::line_descriptor::KeyLine>>, descriptors: &mut core::Vector::<core::Mat>, return_float_descr: bool) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_compute_const_const_vector_Mat_R_vector_vector_KeyLine__R_vector_Mat_R_bool(self.as_raw_BinaryDescriptor(), images.as_raw_VectorOfMat(), keylines.as_raw_mut_VectorOfVectorOfKeyLine(), descriptors.as_raw_mut_VectorOfMat(), return_float_descr) }.into_result()
	}
	
	/// Return descriptor size
	fn descriptor_size(&self) -> Result<i32> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_descriptorSize_const(self.as_raw_BinaryDescriptor()) }.into_result()
	}
	
	/// Return data type
	fn descriptor_type(&self) -> Result<i32> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_descriptorType_const(self.as_raw_BinaryDescriptor()) }.into_result()
	}
	
	/// returns norm mode
	fn default_norm(&self) -> Result<i32> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_defaultNorm_const(self.as_raw_BinaryDescriptor()) }.into_result()
	}
	
}

/// Class implements both functionalities for detection of lines and computation of their
/// binary descriptor.
/// 
/// Class' interface is mainly based on the ones of classical detectors and extractors, such as
/// Feature2d's @ref features2d_main and @ref features2d_match. Retrieved information about lines is
/// stored in line_descriptor::KeyLine objects.
pub struct BinaryDescriptor {
	ptr: *mut c_void
}

opencv_type_boxed! { BinaryDescriptor }

impl Drop for BinaryDescriptor {
	fn drop(&mut self) {
		extern "C" { fn cv_BinaryDescriptor_delete(instance: *mut c_void); }
		unsafe { cv_BinaryDescriptor_delete(self.as_raw_mut_BinaryDescriptor()) };
	}
}

impl BinaryDescriptor {
	#[inline] pub fn as_raw_BinaryDescriptor(&self) -> *const c_void { self.as_raw() }
	#[inline] pub fn as_raw_mut_BinaryDescriptor(&mut self) -> *mut c_void { self.as_raw_mut() }
}

unsafe impl Send for BinaryDescriptor {}

impl core::AlgorithmTrait for BinaryDescriptor {
	#[inline] fn as_raw_Algorithm(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_Algorithm(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl crate::line_descriptor::BinaryDescriptorTrait for BinaryDescriptor {
	#[inline] fn as_raw_BinaryDescriptor(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_BinaryDescriptor(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl BinaryDescriptor {
	/// Constructor
	/// 
	/// ## Parameters
	/// * parameters: configuration parameters BinaryDescriptor::Params
	/// 
	/// If no argument is provided, constructor sets default values (see comments in the code snippet in
	/// previous section). Default values are strongly recommended.
	/// 
	/// ## C++ default parameters
	/// * parameters: BinaryDescriptor::Params()
	pub fn new(parameters: &crate::line_descriptor::BinaryDescriptor_Params) -> Result<crate::line_descriptor::BinaryDescriptor> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_BinaryDescriptor_const_ParamsR(parameters.as_raw_BinaryDescriptor_Params()) }.into_result().map(|r| unsafe { crate::line_descriptor::BinaryDescriptor::opencv_from_extern(r) } )
	}
	
	/// Create a BinaryDescriptor object with default parameters (or with the ones provided)
	/// and return a smart pointer to it
	pub fn create_binary_descriptor() -> Result<core::Ptr::<crate::line_descriptor::BinaryDescriptor>> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_createBinaryDescriptor() }.into_result().map(|r| unsafe { core::Ptr::<crate::line_descriptor::BinaryDescriptor>::opencv_from_extern(r) } )
	}
	
	pub fn create_binary_descriptor_1(mut parameters: crate::line_descriptor::BinaryDescriptor_Params) -> Result<core::Ptr::<crate::line_descriptor::BinaryDescriptor>> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_createBinaryDescriptor_Params(parameters.as_raw_mut_BinaryDescriptor_Params()) }.into_result().map(|r| unsafe { core::Ptr::<crate::line_descriptor::BinaryDescriptor>::opencv_from_extern(r) } )
	}
	
}

/// List of BinaryDescriptor parameters:
pub trait BinaryDescriptor_ParamsTrait {
	fn as_raw_BinaryDescriptor_Params(&self) -> *const c_void;
	fn as_raw_mut_BinaryDescriptor_Params(&mut self) -> *mut c_void;

	/// the number of image octaves (default = 1)
	fn num_of_octave_(&self) -> i32 {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_getPropNumOfOctave__const(self.as_raw_BinaryDescriptor_Params()) }.into_result().expect("Infallible function failed: num_of_octave_")
	}
	
	/// the number of image octaves (default = 1)
	fn set_num_of_octave_(&mut self, val: i32) -> () {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_setPropNumOfOctave__int(self.as_raw_mut_BinaryDescriptor_Params(), val) }.into_result().expect("Infallible function failed: set_num_of_octave_")
	}
	
	/// the width of band; (default: 7)
	fn width_of_band_(&self) -> i32 {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_getPropWidthOfBand__const(self.as_raw_BinaryDescriptor_Params()) }.into_result().expect("Infallible function failed: width_of_band_")
	}
	
	/// the width of band; (default: 7)
	fn set_width_of_band_(&mut self, val: i32) -> () {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_setPropWidthOfBand__int(self.as_raw_mut_BinaryDescriptor_Params(), val) }.into_result().expect("Infallible function failed: set_width_of_band_")
	}
	
	/// image's reduction ratio in construction of Gaussian pyramids
	fn reduction_ratio(&self) -> i32 {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_getPropReductionRatio_const(self.as_raw_BinaryDescriptor_Params()) }.into_result().expect("Infallible function failed: reduction_ratio")
	}
	
	/// image's reduction ratio in construction of Gaussian pyramids
	fn set_reduction_ratio(&mut self, val: i32) -> () {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_setPropReductionRatio_int(self.as_raw_mut_BinaryDescriptor_Params(), val) }.into_result().expect("Infallible function failed: set_reduction_ratio")
	}
	
	fn ksize_(&self) -> i32 {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_getPropKsize__const(self.as_raw_BinaryDescriptor_Params()) }.into_result().expect("Infallible function failed: ksize_")
	}
	
	fn set_ksize_(&mut self, val: i32) -> () {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_setPropKsize__int(self.as_raw_mut_BinaryDescriptor_Params(), val) }.into_result().expect("Infallible function failed: set_ksize_")
	}
	
	/// read parameters from a FileNode object and store them (struct function)
	fn read(&mut self, fn_: &core::FileNode) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_read_const_FileNodeR(self.as_raw_mut_BinaryDescriptor_Params(), fn_.as_raw_FileNode()) }.into_result()
	}
	
	/// store parameters to a FileStorage object (struct function)
	fn write(&self, fs: &mut core::FileStorage) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_write_const_FileStorageR(self.as_raw_BinaryDescriptor_Params(), fs.as_raw_mut_FileStorage()) }.into_result()
	}
	
}

/// List of BinaryDescriptor parameters:
pub struct BinaryDescriptor_Params {
	ptr: *mut c_void
}

opencv_type_boxed! { BinaryDescriptor_Params }

impl Drop for BinaryDescriptor_Params {
	fn drop(&mut self) {
		extern "C" { fn cv_BinaryDescriptor_Params_delete(instance: *mut c_void); }
		unsafe { cv_BinaryDescriptor_Params_delete(self.as_raw_mut_BinaryDescriptor_Params()) };
	}
}

impl BinaryDescriptor_Params {
	#[inline] pub fn as_raw_BinaryDescriptor_Params(&self) -> *const c_void { self.as_raw() }
	#[inline] pub fn as_raw_mut_BinaryDescriptor_Params(&mut self) -> *mut c_void { self.as_raw_mut() }
}

unsafe impl Send for BinaryDescriptor_Params {}

impl crate::line_descriptor::BinaryDescriptor_ParamsTrait for BinaryDescriptor_Params {
	#[inline] fn as_raw_BinaryDescriptor_Params(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_BinaryDescriptor_Params(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl BinaryDescriptor_Params {
	pub fn default() -> Result<crate::line_descriptor::BinaryDescriptor_Params> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptor_Params_Params() }.into_result().map(|r| unsafe { crate::line_descriptor::BinaryDescriptor_Params::opencv_from_extern(r) } )
	}
	
}

/// furnishes all functionalities for querying a dataset provided by user or internal to
/// class (that user must, anyway, populate) on the model of @ref features2d_match
/// 
/// 
/// Once descriptors have been extracted from an image (both they represent lines and points), it
/// becomes interesting to be able to match a descriptor with another one extracted from a different
/// image and representing the same line or point, seen from a differente perspective or on a different
/// scale. In reaching such goal, the main headache is designing an efficient search algorithm to
/// associate a query descriptor to one extracted from a dataset. In the following, a matching modality
/// based on *Multi-Index Hashing (MiHashing)* will be described.
/// 
/// Multi-Index Hashing
/// -------------------
/// 
/// The theory described in this section is based on [MIH](https://docs.opencv.org/3.4.10/d0/de3/citelist.html#CITEREF_MIH) . Given a dataset populated with binary
/// codes, each code is indexed *m* times into *m* different hash tables, according to *m* substrings it
/// has been divided into. Thus, given a query code, all the entries close to it at least in one
/// substring are returned by search as *neighbor candidates*. Returned entries are then checked for
/// validity by verifying that their full codes are not distant (in Hamming space) more than *r* bits
/// from query code. In details, each binary code **h** composed of *b* bits is divided into *m*
/// disjoint substrings ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bh%7D%5E%7B%281%29%7D%2C%20%2E%2E%2E%2C%20%5Cmathbf%7Bh%7D%5E%7B%28m%29%7D), each with length
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20b%2Fm%20%5Crfloor) or ![inline formula](https://latex.codecogs.com/png.latex?%5Clceil%20b%2Fm%20%5Crceil) bits. Formally, when two codes **h** and **g** differ
/// by at the most *r* bits, in at the least one of their *m* substrings they differ by at the most
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20r%2Fm%20%5Crfloor) bits. In particular, when ![inline formula](https://latex.codecogs.com/png.latex?%7C%7C%5Cmathbf%7Bh%7D%2D%5Cmathbf%7Bg%7D%7C%7C%5FH%20%5Cle%20r) (where ![inline formula](https://latex.codecogs.com/png.latex?%7C%7C%2E%7C%7C%5FH)
/// is the Hamming norm), there must exist a substring *k* (with ![inline formula](https://latex.codecogs.com/png.latex?1%20%5Cle%20k%20%5Cle%20m)) such that
/// 
/// ![block formula](https://latex.codecogs.com/png.latex?%7C%7C%5Cmathbf%7Bh%7D%5E%7B%28k%29%7D%20%2D%20%5Cmathbf%7Bg%7D%5E%7B%28k%29%7D%7C%7C%5FH%20%5Cle%20%5Cleft%5Clfloor%20%5Cfrac%7Br%7D%7Bm%7D%20%5Cright%5Crfloor%20%2E)
/// 
/// That means that if Hamming distance between each of the *m* substring is strictly greater than
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20r%2Fm%20%5Crfloor), then ![inline formula](https://latex.codecogs.com/png.latex?%7C%7C%5Cmathbf%7Bh%7D%2D%5Cmathbf%7Bg%7D%7C%7C%5FH) must be larger that *r* and that is a
/// contradiction. If the codes in dataset are divided into *m* substrings, then *m* tables will be
/// built. Given a query **q** with substrings ![inline formula](https://latex.codecogs.com/png.latex?%5C%7B%5Cmathbf%7Bq%7D%5E%7B%28i%29%7D%5C%7D%5Em%5F%7Bi%3D1%7D), *i*-th hash table is
/// searched for entries distant at the most ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20r%2Fm%20%5Crfloor) from ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bq%7D%5E%7B%28i%29%7D) and a set of
/// candidates ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathcal%7BN%7D%5Fi%28%5Cmathbf%7Bq%7D%29) is obtained. The union of sets
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathcal%7BN%7D%28%5Cmathbf%7Bq%7D%29%20%3D%20%5Cbigcup%5Fi%20%5Cmathcal%7BN%7D%5Fi%28%5Cmathbf%7Bq%7D%29) is a superset of the *r*-neighbors
/// of **q**. Then, last step of algorithm is computing the Hamming distance between **q** and each
/// element in ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathcal%7BN%7D%28%5Cmathbf%7Bq%7D%29), deleting the codes that are distant more that *r* from **q**.
pub trait BinaryDescriptorMatcherTrait: core::AlgorithmTrait {
	fn as_raw_BinaryDescriptorMatcher(&self) -> *const c_void;
	fn as_raw_mut_BinaryDescriptorMatcher(&mut self) -> *mut c_void;

	/// For every input query descriptor, retrieve the best matching one from a dataset provided from user
	/// or from the one internal to class
	/// 
	/// ## Parameters
	/// * queryDescriptors: query descriptors
	/// * trainDescriptors: dataset of descriptors furnished by user
	/// * matches: vector to host retrieved matches
	/// * mask: mask to select which input descriptors must be matched to one in dataset
	/// 
	/// ## C++ default parameters
	/// * mask: Mat()
	fn match_(&self, query_descriptors: &core::Mat, train_descriptors: &core::Mat, matches: &mut core::Vector::<core::DMatch>, mask: &core::Mat) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_match_const_const_MatR_const_MatR_vector_DMatch_R_const_MatR(self.as_raw_BinaryDescriptorMatcher(), query_descriptors.as_raw_Mat(), train_descriptors.as_raw_Mat(), matches.as_raw_mut_VectorOfDMatch(), mask.as_raw_Mat()) }.into_result()
	}
	
	/// For every input query descriptor, retrieve the best matching one from a dataset provided from user
	/// or from the one internal to class
	/// 
	/// ## Parameters
	/// * queryDescriptors: query descriptors
	/// * trainDescriptors: dataset of descriptors furnished by user
	/// * matches: vector to host retrieved matches
	/// * mask: mask to select which input descriptors must be matched to one in dataset
	/// 
	/// ## Overloaded parameters
	/// 
	/// * queryDescriptors: query descriptors
	/// * matches: vector to host retrieved matches
	/// * masks: vector of masks to select which input descriptors must be matched to one in dataset
	/// (the *i*-th mask in vector indicates whether each input query can be matched with descriptors in
	/// dataset relative to *i*-th image)
	/// 
	/// ## C++ default parameters
	/// * masks: std::vector<Mat>()
	fn match_query(&mut self, query_descriptors: &core::Mat, matches: &mut core::Vector::<core::DMatch>, masks: &core::Vector::<core::Mat>) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_match_const_MatR_vector_DMatch_R_const_vector_Mat_R(self.as_raw_mut_BinaryDescriptorMatcher(), query_descriptors.as_raw_Mat(), matches.as_raw_mut_VectorOfDMatch(), masks.as_raw_VectorOfMat()) }.into_result()
	}
	
	/// For every input query descriptor, retrieve the best *k* matching ones from a dataset provided from
	/// user or from the one internal to class
	/// 
	/// ## Parameters
	/// * queryDescriptors: query descriptors
	/// * trainDescriptors: dataset of descriptors furnished by user
	/// * matches: vector to host retrieved matches
	/// * k: number of the closest descriptors to be returned for every input query
	/// * mask: mask to select which input descriptors must be matched to ones in dataset
	/// * compactResult: flag to obtain a compact result (if true, a vector that doesn't contain any
	/// matches for a given query is not inserted in final result)
	/// 
	/// ## C++ default parameters
	/// * mask: Mat()
	/// * compact_result: false
	fn knn_match(&self, query_descriptors: &core::Mat, train_descriptors: &core::Mat, matches: &mut core::Vector::<core::Vector::<core::DMatch>>, k: i32, mask: &core::Mat, compact_result: bool) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_knnMatch_const_const_MatR_const_MatR_vector_vector_DMatch__R_int_const_MatR_bool(self.as_raw_BinaryDescriptorMatcher(), query_descriptors.as_raw_Mat(), train_descriptors.as_raw_Mat(), matches.as_raw_mut_VectorOfVectorOfDMatch(), k, mask.as_raw_Mat(), compact_result) }.into_result()
	}
	
	/// For every input query descriptor, retrieve the best *k* matching ones from a dataset provided from
	/// user or from the one internal to class
	/// 
	/// ## Parameters
	/// * queryDescriptors: query descriptors
	/// * trainDescriptors: dataset of descriptors furnished by user
	/// * matches: vector to host retrieved matches
	/// * k: number of the closest descriptors to be returned for every input query
	/// * mask: mask to select which input descriptors must be matched to ones in dataset
	/// * compactResult: flag to obtain a compact result (if true, a vector that doesn't contain any
	/// matches for a given query is not inserted in final result)
	/// 
	/// ## Overloaded parameters
	/// 
	/// * queryDescriptors: query descriptors
	/// * matches: vector to host retrieved matches
	/// * k: number of the closest descriptors to be returned for every input query
	/// * masks: vector of masks to select which input descriptors must be matched to ones in dataset
	/// (the *i*-th mask in vector indicates whether each input query can be matched with descriptors in
	/// dataset relative to *i*-th image)
	/// * compactResult: flag to obtain a compact result (if true, a vector that doesn't contain any
	/// matches for a given query is not inserted in final result)
	/// 
	/// ## C++ default parameters
	/// * masks: std::vector<Mat>()
	/// * compact_result: false
	fn knn_match_query(&mut self, query_descriptors: &core::Mat, matches: &mut core::Vector::<core::Vector::<core::DMatch>>, k: i32, masks: &core::Vector::<core::Mat>, compact_result: bool) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_knnMatch_const_MatR_vector_vector_DMatch__R_int_const_vector_Mat_R_bool(self.as_raw_mut_BinaryDescriptorMatcher(), query_descriptors.as_raw_Mat(), matches.as_raw_mut_VectorOfVectorOfDMatch(), k, masks.as_raw_VectorOfMat(), compact_result) }.into_result()
	}
	
	/// For every input query descriptor, retrieve, from a dataset provided from user or from the one
	/// internal to class, all the descriptors that are not further than *maxDist* from input query
	/// 
	/// ## Parameters
	/// * queryDescriptors: query descriptors
	/// * trainDescriptors: dataset of descriptors furnished by user
	/// * matches: vector to host retrieved matches
	/// * maxDistance: search radius
	/// * mask: mask to select which input descriptors must be matched to ones in dataset
	/// * compactResult: flag to obtain a compact result (if true, a vector that doesn't contain any
	/// matches for a given query is not inserted in final result)
	/// 
	/// ## C++ default parameters
	/// * mask: Mat()
	/// * compact_result: false
	fn radius_match(&self, query_descriptors: &core::Mat, train_descriptors: &core::Mat, matches: &mut core::Vector::<core::Vector::<core::DMatch>>, max_distance: f32, mask: &core::Mat, compact_result: bool) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_radiusMatch_const_const_MatR_const_MatR_vector_vector_DMatch__R_float_const_MatR_bool(self.as_raw_BinaryDescriptorMatcher(), query_descriptors.as_raw_Mat(), train_descriptors.as_raw_Mat(), matches.as_raw_mut_VectorOfVectorOfDMatch(), max_distance, mask.as_raw_Mat(), compact_result) }.into_result()
	}
	
	/// For every input query descriptor, retrieve, from a dataset provided from user or from the one
	/// internal to class, all the descriptors that are not further than *maxDist* from input query
	/// 
	/// ## Parameters
	/// * queryDescriptors: query descriptors
	/// * trainDescriptors: dataset of descriptors furnished by user
	/// * matches: vector to host retrieved matches
	/// * maxDistance: search radius
	/// * mask: mask to select which input descriptors must be matched to ones in dataset
	/// * compactResult: flag to obtain a compact result (if true, a vector that doesn't contain any
	/// matches for a given query is not inserted in final result)
	/// 
	/// ## Overloaded parameters
	/// 
	/// * queryDescriptors: query descriptors
	/// * matches: vector to host retrieved matches
	/// * maxDistance: search radius
	/// * masks: vector of masks to select which input descriptors must be matched to ones in dataset
	/// (the *i*-th mask in vector indicates whether each input query can be matched with descriptors in
	/// dataset relative to *i*-th image)
	/// * compactResult: flag to obtain a compact result (if true, a vector that doesn't contain any
	/// matches for a given query is not inserted in final result)
	/// 
	/// ## C++ default parameters
	/// * masks: std::vector<Mat>()
	/// * compact_result: false
	fn radius_match_1(&mut self, query_descriptors: &core::Mat, matches: &mut core::Vector::<core::Vector::<core::DMatch>>, max_distance: f32, masks: &core::Vector::<core::Mat>, compact_result: bool) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_radiusMatch_const_MatR_vector_vector_DMatch__R_float_const_vector_Mat_R_bool(self.as_raw_mut_BinaryDescriptorMatcher(), query_descriptors.as_raw_Mat(), matches.as_raw_mut_VectorOfVectorOfDMatch(), max_distance, masks.as_raw_VectorOfMat(), compact_result) }.into_result()
	}
	
	/// Store locally new descriptors to be inserted in dataset, without updating dataset.
	/// 
	/// ## Parameters
	/// * descriptors: matrices containing descriptors to be inserted into dataset
	/// 
	/// 
	/// Note: Each matrix *i* in **descriptors** should contain descriptors relative to lines extracted from
	/// *i*-th image.
	fn add(&mut self, descriptors: &core::Vector::<core::Mat>) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_add_const_vector_Mat_R(self.as_raw_mut_BinaryDescriptorMatcher(), descriptors.as_raw_VectorOfMat()) }.into_result()
	}
	
	/// Update dataset by inserting into it all descriptors that were stored locally by *add* function.
	/// 
	/// 
	/// Note: Every time this function is invoked, current dataset is deleted and locally stored descriptors
	/// are inserted into dataset. The locally stored copy of just inserted descriptors is then removed.
	fn train(&mut self) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_train(self.as_raw_mut_BinaryDescriptorMatcher()) }.into_result()
	}
	
	/// Clear dataset and internal data
	fn clear(&mut self) -> Result<()> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_clear(self.as_raw_mut_BinaryDescriptorMatcher()) }.into_result()
	}
	
}

/// furnishes all functionalities for querying a dataset provided by user or internal to
/// class (that user must, anyway, populate) on the model of @ref features2d_match
/// 
/// 
/// Once descriptors have been extracted from an image (both they represent lines and points), it
/// becomes interesting to be able to match a descriptor with another one extracted from a different
/// image and representing the same line or point, seen from a differente perspective or on a different
/// scale. In reaching such goal, the main headache is designing an efficient search algorithm to
/// associate a query descriptor to one extracted from a dataset. In the following, a matching modality
/// based on *Multi-Index Hashing (MiHashing)* will be described.
/// 
/// Multi-Index Hashing
/// -------------------
/// 
/// The theory described in this section is based on [MIH](https://docs.opencv.org/3.4.10/d0/de3/citelist.html#CITEREF_MIH) . Given a dataset populated with binary
/// codes, each code is indexed *m* times into *m* different hash tables, according to *m* substrings it
/// has been divided into. Thus, given a query code, all the entries close to it at least in one
/// substring are returned by search as *neighbor candidates*. Returned entries are then checked for
/// validity by verifying that their full codes are not distant (in Hamming space) more than *r* bits
/// from query code. In details, each binary code **h** composed of *b* bits is divided into *m*
/// disjoint substrings ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bh%7D%5E%7B%281%29%7D%2C%20%2E%2E%2E%2C%20%5Cmathbf%7Bh%7D%5E%7B%28m%29%7D), each with length
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20b%2Fm%20%5Crfloor) or ![inline formula](https://latex.codecogs.com/png.latex?%5Clceil%20b%2Fm%20%5Crceil) bits. Formally, when two codes **h** and **g** differ
/// by at the most *r* bits, in at the least one of their *m* substrings they differ by at the most
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20r%2Fm%20%5Crfloor) bits. In particular, when ![inline formula](https://latex.codecogs.com/png.latex?%7C%7C%5Cmathbf%7Bh%7D%2D%5Cmathbf%7Bg%7D%7C%7C%5FH%20%5Cle%20r) (where ![inline formula](https://latex.codecogs.com/png.latex?%7C%7C%2E%7C%7C%5FH)
/// is the Hamming norm), there must exist a substring *k* (with ![inline formula](https://latex.codecogs.com/png.latex?1%20%5Cle%20k%20%5Cle%20m)) such that
/// 
/// ![block formula](https://latex.codecogs.com/png.latex?%7C%7C%5Cmathbf%7Bh%7D%5E%7B%28k%29%7D%20%2D%20%5Cmathbf%7Bg%7D%5E%7B%28k%29%7D%7C%7C%5FH%20%5Cle%20%5Cleft%5Clfloor%20%5Cfrac%7Br%7D%7Bm%7D%20%5Cright%5Crfloor%20%2E)
/// 
/// That means that if Hamming distance between each of the *m* substring is strictly greater than
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20r%2Fm%20%5Crfloor), then ![inline formula](https://latex.codecogs.com/png.latex?%7C%7C%5Cmathbf%7Bh%7D%2D%5Cmathbf%7Bg%7D%7C%7C%5FH) must be larger that *r* and that is a
/// contradiction. If the codes in dataset are divided into *m* substrings, then *m* tables will be
/// built. Given a query **q** with substrings ![inline formula](https://latex.codecogs.com/png.latex?%5C%7B%5Cmathbf%7Bq%7D%5E%7B%28i%29%7D%5C%7D%5Em%5F%7Bi%3D1%7D), *i*-th hash table is
/// searched for entries distant at the most ![inline formula](https://latex.codecogs.com/png.latex?%5Clfloor%20r%2Fm%20%5Crfloor) from ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathbf%7Bq%7D%5E%7B%28i%29%7D) and a set of
/// candidates ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathcal%7BN%7D%5Fi%28%5Cmathbf%7Bq%7D%29) is obtained. The union of sets
/// ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathcal%7BN%7D%28%5Cmathbf%7Bq%7D%29%20%3D%20%5Cbigcup%5Fi%20%5Cmathcal%7BN%7D%5Fi%28%5Cmathbf%7Bq%7D%29) is a superset of the *r*-neighbors
/// of **q**. Then, last step of algorithm is computing the Hamming distance between **q** and each
/// element in ![inline formula](https://latex.codecogs.com/png.latex?%5Cmathcal%7BN%7D%28%5Cmathbf%7Bq%7D%29), deleting the codes that are distant more that *r* from **q**.
pub struct BinaryDescriptorMatcher {
	ptr: *mut c_void
}

opencv_type_boxed! { BinaryDescriptorMatcher }

impl Drop for BinaryDescriptorMatcher {
	fn drop(&mut self) {
		extern "C" { fn cv_BinaryDescriptorMatcher_delete(instance: *mut c_void); }
		unsafe { cv_BinaryDescriptorMatcher_delete(self.as_raw_mut_BinaryDescriptorMatcher()) };
	}
}

impl BinaryDescriptorMatcher {
	#[inline] pub fn as_raw_BinaryDescriptorMatcher(&self) -> *const c_void { self.as_raw() }
	#[inline] pub fn as_raw_mut_BinaryDescriptorMatcher(&mut self) -> *mut c_void { self.as_raw_mut() }
}

unsafe impl Send for BinaryDescriptorMatcher {}

impl core::AlgorithmTrait for BinaryDescriptorMatcher {
	#[inline] fn as_raw_Algorithm(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_Algorithm(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl crate::line_descriptor::BinaryDescriptorMatcherTrait for BinaryDescriptorMatcher {
	#[inline] fn as_raw_BinaryDescriptorMatcher(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_BinaryDescriptorMatcher(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl BinaryDescriptorMatcher {
	/// Create a BinaryDescriptorMatcher object and return a smart pointer to it.
	pub fn create_binary_descriptor_matcher() -> Result<core::Ptr::<crate::line_descriptor::BinaryDescriptorMatcher>> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_createBinaryDescriptorMatcher() }.into_result().map(|r| unsafe { core::Ptr::<crate::line_descriptor::BinaryDescriptorMatcher>::opencv_from_extern(r) } )
	}
	
	/// Constructor.
	/// 
	/// The BinaryDescriptorMatcher constructed is able to store and manage 256-bits long entries.
	pub fn default() -> Result<crate::line_descriptor::BinaryDescriptorMatcher> {
		unsafe { sys::cv_line_descriptor_BinaryDescriptorMatcher_BinaryDescriptorMatcher() }.into_result().map(|r| unsafe { crate::line_descriptor::BinaryDescriptorMatcher::opencv_from_extern(r) } )
	}
	
}

/// struct for drawing options
#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq)]
pub struct DrawLinesMatchesFlags {
	__rust_private: [u8; 0],
}

opencv_type_simple! { crate::line_descriptor::DrawLinesMatchesFlags }

impl DrawLinesMatchesFlags {
}

/// A class to represent a line
/// 
/// As aformentioned, it is been necessary to design a class that fully stores the information needed to
/// characterize completely a line and plot it on image it was extracted from, when required.
/// 
/// *KeyLine* class has been created for such goal; it is mainly inspired to Feature2d's KeyPoint class,
/// since KeyLine shares some of *KeyPoint*'s fields, even if a part of them assumes a different
/// meaning, when speaking about lines. In particular:
/// 
/// *   the *class_id* field is used to gather lines extracted from different octaves which refer to
///    same line inside original image (such lines and the one they represent in original image share
///    the same *class_id* value)
/// *   the *angle* field represents line's slope with respect to (positive) X axis
/// *   the *pt* field represents line's midpoint
/// *   the *response* field is computed as the ratio between the line's length and maximum between
///    image's width and height
/// *   the *size* field is the area of the smallest rectangle containing line
/// 
/// Apart from fields inspired to KeyPoint class, KeyLines stores information about extremes of line in
/// original image and in octave it was extracted from, about line's length and number of pixels it
/// covers.
#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq)]
pub struct KeyLine {
	/// orientation of the line
	pub angle: f32,
	/// object ID, that can be used to cluster keylines by the line they represent
	pub class_id: i32,
	/// octave (pyramid layer), from which the keyline has been extracted
	pub octave: i32,
	/// coordinates of the middlepoint
	pub pt: core::Point2f,
	/// the response, by which the strongest keylines have been selected.
	/// It's represented by the ratio between line's length and maximum between
	/// image's width and height
	pub response: f32,
	/// minimum area containing line
	pub size: f32,
	/// lines's extremes in original image
	pub start_point_x: f32,
	pub start_point_y: f32,
	pub end_point_x: f32,
	pub end_point_y: f32,
	/// line's extremes in image it was extracted from
	pub s_point_in_octave_x: f32,
	pub s_point_in_octave_y: f32,
	pub e_point_in_octave_x: f32,
	pub e_point_in_octave_y: f32,
	/// the length of line
	pub line_length: f32,
	/// number of pixels covered by the line
	pub num_of_pixels: i32,
}

opencv_type_simple! { crate::line_descriptor::KeyLine }

impl KeyLine {
	/// Returns the start point of the line in the original image
	pub fn get_start_point(self) -> Result<core::Point2f> {
		unsafe { sys::cv_line_descriptor_KeyLine_getStartPoint_const(self.opencv_to_extern()) }.into_result()
	}
	
	/// Returns the end point of the line in the original image
	pub fn get_end_point(self) -> Result<core::Point2f> {
		unsafe { sys::cv_line_descriptor_KeyLine_getEndPoint_const(self.opencv_to_extern()) }.into_result()
	}
	
	/// Returns the start point of the line in the octave it was extracted from
	pub fn get_start_point_in_octave(self) -> Result<core::Point2f> {
		unsafe { sys::cv_line_descriptor_KeyLine_getStartPointInOctave_const(self.opencv_to_extern()) }.into_result()
	}
	
	/// Returns the end point of the line in the octave it was extracted from
	pub fn get_end_point_in_octave(self) -> Result<core::Point2f> {
		unsafe { sys::cv_line_descriptor_KeyLine_getEndPointInOctave_const(self.opencv_to_extern()) }.into_result()
	}
	
	/// constructor
	pub fn default() -> Result<crate::line_descriptor::KeyLine> {
		unsafe { sys::cv_line_descriptor_KeyLine_KeyLine() }.into_result()
	}
	
}

pub trait LSDDetectorTrait: core::AlgorithmTrait {
	fn as_raw_LSDDetector(&self) -> *const c_void;
	fn as_raw_mut_LSDDetector(&mut self) -> *mut c_void;

	/// Detect lines inside an image.
	/// 
	/// ## Parameters
	/// * image: input image
	/// * keypoints: vector that will store extracted lines for one or more images
	/// * scale: scale factor used in pyramids generation
	/// * numOctaves: number of octaves inside pyramid
	/// * mask: mask matrix to detect only KeyLines of interest
	/// 
	/// ## C++ default parameters
	/// * mask: Mat()
	fn detect(&mut self, image: &core::Mat, keypoints: &mut core::Vector::<crate::line_descriptor::KeyLine>, scale: i32, num_octaves: i32, mask: &core::Mat) -> Result<()> {
		unsafe { sys::cv_line_descriptor_LSDDetector_detect_const_MatR_vector_KeyLine_R_int_int_const_MatR(self.as_raw_mut_LSDDetector(), image.as_raw_Mat(), keypoints.as_raw_mut_VectorOfKeyLine(), scale, num_octaves, mask.as_raw_Mat()) }.into_result()
	}
	
	/// Detect lines inside an image.
	/// 
	/// ## Parameters
	/// * image: input image
	/// * keypoints: vector that will store extracted lines for one or more images
	/// * scale: scale factor used in pyramids generation
	/// * numOctaves: number of octaves inside pyramid
	/// * mask: mask matrix to detect only KeyLines of interest
	/// 
	/// ## Overloaded parameters
	/// 
	/// * images: input images
	/// * keylines: set of vectors that will store extracted lines for one or more images
	/// * scale: scale factor used in pyramids generation
	/// * numOctaves: number of octaves inside pyramid
	/// * masks: vector of mask matrices to detect only KeyLines of interest from each input image
	/// 
	/// ## C++ default parameters
	/// * masks: std::vector<Mat>()
	fn detect_multiple(&self, images: &core::Vector::<core::Mat>, keylines: &mut core::Vector::<core::Vector::<crate::line_descriptor::KeyLine>>, scale: i32, num_octaves: i32, masks: &core::Vector::<core::Mat>) -> Result<()> {
		unsafe { sys::cv_line_descriptor_LSDDetector_detect_const_const_vector_Mat_R_vector_vector_KeyLine__R_int_int_const_vector_Mat_R(self.as_raw_LSDDetector(), images.as_raw_VectorOfMat(), keylines.as_raw_mut_VectorOfVectorOfKeyLine(), scale, num_octaves, masks.as_raw_VectorOfMat()) }.into_result()
	}
	
}

pub struct LSDDetector {
	ptr: *mut c_void
}

opencv_type_boxed! { LSDDetector }

impl Drop for LSDDetector {
	fn drop(&mut self) {
		extern "C" { fn cv_LSDDetector_delete(instance: *mut c_void); }
		unsafe { cv_LSDDetector_delete(self.as_raw_mut_LSDDetector()) };
	}
}

impl LSDDetector {
	#[inline] pub fn as_raw_LSDDetector(&self) -> *const c_void { self.as_raw() }
	#[inline] pub fn as_raw_mut_LSDDetector(&mut self) -> *mut c_void { self.as_raw_mut() }
}

unsafe impl Send for LSDDetector {}

impl core::AlgorithmTrait for LSDDetector {
	#[inline] fn as_raw_Algorithm(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_Algorithm(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl crate::line_descriptor::LSDDetectorTrait for LSDDetector {
	#[inline] fn as_raw_LSDDetector(&self) -> *const c_void { self.as_raw() }
	#[inline] fn as_raw_mut_LSDDetector(&mut self) -> *mut c_void { self.as_raw_mut() }
}

impl LSDDetector {
	pub fn default() -> Result<crate::line_descriptor::LSDDetector> {
		unsafe { sys::cv_line_descriptor_LSDDetector_LSDDetector() }.into_result().map(|r| unsafe { crate::line_descriptor::LSDDetector::opencv_from_extern(r) } )
	}
	
	pub fn new(_params: crate::line_descriptor::LSDParam) -> Result<crate::line_descriptor::LSDDetector> {
		unsafe { sys::cv_line_descriptor_LSDDetector_LSDDetector_LSDParam(_params.opencv_to_extern()) }.into_result().map(|r| unsafe { crate::line_descriptor::LSDDetector::opencv_from_extern(r) } )
	}
	
	/// Creates ad LSDDetector object, using smart pointers.
	pub fn create_lsd_detector() -> Result<core::Ptr::<crate::line_descriptor::LSDDetector>> {
		unsafe { sys::cv_line_descriptor_LSDDetector_createLSDDetector() }.into_result().map(|r| unsafe { core::Ptr::<crate::line_descriptor::LSDDetector>::opencv_from_extern(r) } )
	}
	
	pub fn create_lsd_detector_with_params(params: crate::line_descriptor::LSDParam) -> Result<core::Ptr::<crate::line_descriptor::LSDDetector>> {
		unsafe { sys::cv_line_descriptor_LSDDetector_createLSDDetector_LSDParam(params.opencv_to_extern()) }.into_result().map(|r| unsafe { core::Ptr::<crate::line_descriptor::LSDDetector>::opencv_from_extern(r) } )
	}
	
}

/// Lines extraction methodology
/// ----------------------------
/// 
/// The lines extraction methodology described in the following is mainly based on [EDL](https://docs.opencv.org/3.4.10/d0/de3/citelist.html#CITEREF_EDL) . The
/// extraction starts with a Gaussian pyramid generated from an original image, downsampled N-1 times,
/// blurred N times, to obtain N layers (one for each octave), with layer 0 corresponding to input
/// image. Then, from each layer (octave) in the pyramid, lines are extracted using LSD algorithm.
/// 
/// Differently from EDLine lines extractor used in original article, LSD furnishes information only
/// about lines extremes; thus, additional information regarding slope and equation of line are computed
/// via analytic methods. The number of pixels is obtained using *LineIterator*. Extracted lines are
/// returned in the form of KeyLine objects, but since extraction is based on a method different from
/// the one used in *BinaryDescriptor* class, data associated to a line's extremes in original image and
/// in octave it was extracted from, coincide. KeyLine's field *class_id* is used as an index to
/// indicate the order of extraction of a line inside a single octave.
#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq)]
pub struct LSDParam {
	pub scale: f64,
	pub sigma_scale: f64,
	pub quant: f64,
	pub ang_th: f64,
	pub log_eps: f64,
	pub density_th: f64,
	pub n_bins: i32,
}

opencv_type_simple! { crate::line_descriptor::LSDParam }

impl LSDParam {
	pub fn default() -> Result<crate::line_descriptor::LSDParam> {
		unsafe { sys::cv_line_descriptor_LSDParam_LSDParam() }.into_result()
	}
	
}
