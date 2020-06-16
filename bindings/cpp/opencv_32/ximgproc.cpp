#include "common.hpp"
#include <opencv2/ximgproc.hpp>
#include "ximgproc_types.hpp"

extern "C" {
	Result_void cv_ximgproc_FastHoughTransform_const__InputArrayR_const__OutputArrayR_int_int_int_int(const cv::_InputArray* src, const cv::_OutputArray* dst, int dstMatDepth, int angleRange, int op, int makeSkew) {
		try {
			cv::ximgproc::FastHoughTransform(*src, *dst, dstMatDepth, angleRange, op, makeSkew);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_GradientDericheX_const__InputArrayR_const__OutputArrayR_double_double(const cv::_InputArray* _op, const cv::_OutputArray* _dst, double alphaDerive, double alphaMean) {
		try {
			cv::ximgproc::GradientDericheX(*_op, *_dst, alphaDerive, alphaMean);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_GradientDericheY_const__InputArrayR_const__OutputArrayR_double_double(const cv::_InputArray* _op, const cv::_OutputArray* _dst, double alphaDerive, double alphaMean) {
		try {
			cv::ximgproc::GradientDericheY(*_op, *_dst, alphaDerive, alphaMean);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_GradientPaillouX_const__InputArrayR_const__OutputArrayR_double_double(const cv::_InputArray* op, const cv::_OutputArray* _dst, double alpha, double omega) {
		try {
			cv::ximgproc::GradientPaillouX(*op, *_dst, alpha, omega);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_GradientPaillouY_const__InputArrayR_const__OutputArrayR_double_double(const cv::_InputArray* op, const cv::_OutputArray* _dst, double alpha, double omega) {
		try {
			cv::ximgproc::GradientPaillouY(*op, *_dst, alpha, omega);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Vec4i> cv_ximgproc_HoughPoint2Line_const_PointR_const__InputArrayR_int_int_int(const cv::Point* houghPoint, const cv::_InputArray* srcImgInfo, int angleRange, int makeSkew, int rules) {
		try {
			cv::Vec4i ret = cv::ximgproc::HoughPoint2Line(*houghPoint, *srcImgInfo, angleRange, makeSkew, rules);
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Vec4i>))
	}
	
	Result_void cv_ximgproc_amFilter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_double_double_bool(const cv::_InputArray* joint, const cv::_InputArray* src, const cv::_OutputArray* dst, double sigma_s, double sigma_r, bool adjust_outliers) {
		try {
			cv::ximgproc::amFilter(*joint, *src, *dst, sigma_s, sigma_r, adjust_outliers);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_bilateralTextureFilter_const__InputArrayR_const__OutputArrayR_int_int_double_double(const cv::_InputArray* src, const cv::_OutputArray* dst, int fr, int numIter, double sigmaAlpha, double sigmaAvg) {
		try {
			cv::ximgproc::bilateralTextureFilter(*src, *dst, fr, numIter, sigmaAlpha, sigmaAvg);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<double> cv_ximgproc_computeBadPixelPercent_const__InputArrayR_const__InputArrayR_Rect_int(const cv::_InputArray* GT, const cv::_InputArray* src, const cv::Rect* ROI, int thresh) {
		try {
			double ret = cv::ximgproc::computeBadPixelPercent(*GT, *src, *ROI, thresh);
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result<double> cv_ximgproc_computeMSE_const__InputArrayR_const__InputArrayR_Rect(const cv::_InputArray* GT, const cv::_InputArray* src, const cv::Rect* ROI) {
		try {
			double ret = cv::ximgproc::computeMSE(*GT, *src, *ROI);
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result_void cv_ximgproc_covarianceEstimation_const__InputArrayR_const__OutputArrayR_int_int(const cv::_InputArray* src, const cv::_OutputArray* dst, int windowRows, int windowCols) {
		try {
			cv::ximgproc::covarianceEstimation(*src, *dst, windowRows, windowCols);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>*> cv_ximgproc_createAMFilter_double_double_bool(double sigma_s, double sigma_r, bool adjust_outliers) {
		try {
			cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter> ret = cv::ximgproc::createAMFilter(sigma_s, sigma_r, adjust_outliers);
			return Ok(new cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::DTFilter>*> cv_ximgproc_createDTFilter_const__InputArrayR_double_double_int_int(const cv::_InputArray* guide, double sigmaSpatial, double sigmaColor, int mode, int numIters) {
		try {
			cv::Ptr<cv::ximgproc::DTFilter> ret = cv::ximgproc::createDTFilter(*guide, sigmaSpatial, sigmaColor, mode, numIters);
			return Ok(new cv::Ptr<cv::ximgproc::DTFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::DTFilter>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::DisparityWLSFilter>*> cv_ximgproc_createDisparityWLSFilterGeneric_bool(bool use_confidence) {
		try {
			cv::Ptr<cv::ximgproc::DisparityWLSFilter> ret = cv::ximgproc::createDisparityWLSFilterGeneric(use_confidence);
			return Ok(new cv::Ptr<cv::ximgproc::DisparityWLSFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::DisparityWLSFilter>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::DisparityWLSFilter>*> cv_ximgproc_createDisparityWLSFilter_Ptr_StereoMatcher_(cv::Ptr<cv::StereoMatcher>* matcher_left) {
		try {
			cv::Ptr<cv::ximgproc::DisparityWLSFilter> ret = cv::ximgproc::createDisparityWLSFilter(*matcher_left);
			return Ok(new cv::Ptr<cv::ximgproc::DisparityWLSFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::DisparityWLSFilter>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::EdgeAwareInterpolator>*> cv_ximgproc_createEdgeAwareInterpolator() {
		try {
			cv::Ptr<cv::ximgproc::EdgeAwareInterpolator> ret = cv::ximgproc::createEdgeAwareInterpolator();
			return Ok(new cv::Ptr<cv::ximgproc::EdgeAwareInterpolator>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::EdgeAwareInterpolator>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter>*> cv_ximgproc_createFastGlobalSmootherFilter_const__InputArrayR_double_double_double_int(const cv::_InputArray* guide, double lambda, double sigma_color, double lambda_attenuation, int num_iter) {
		try {
			cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter> ret = cv::ximgproc::createFastGlobalSmootherFilter(*guide, lambda, sigma_color, lambda_attenuation, num_iter);
			return Ok(new cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::FastLineDetector>*> cv_ximgproc_createFastLineDetector_int_float_double_double_int_bool(int _length_threshold, float _distance_threshold, double _canny_th1, double _canny_th2, int _canny_aperture_size, bool _do_merge) {
		try {
			cv::Ptr<cv::ximgproc::FastLineDetector> ret = cv::ximgproc::createFastLineDetector(_length_threshold, _distance_threshold, _canny_th1, _canny_th2, _canny_aperture_size, _do_merge);
			return Ok(new cv::Ptr<cv::ximgproc::FastLineDetector>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::FastLineDetector>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::GuidedFilter>*> cv_ximgproc_createGuidedFilter_const__InputArrayR_int_double(const cv::_InputArray* guide, int radius, double eps) {
		try {
			cv::Ptr<cv::ximgproc::GuidedFilter> ret = cv::ximgproc::createGuidedFilter(*guide, radius, eps);
			return Ok(new cv::Ptr<cv::ximgproc::GuidedFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::GuidedFilter>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::RFFeatureGetter>*> cv_ximgproc_createRFFeatureGetter() {
		try {
			cv::Ptr<cv::ximgproc::RFFeatureGetter> ret = cv::ximgproc::createRFFeatureGetter();
			return Ok(new cv::Ptr<cv::ximgproc::RFFeatureGetter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::RFFeatureGetter>*>))
	}
	
	Result<cv::Ptr<cv::StereoMatcher>*> cv_ximgproc_createRightMatcher_Ptr_StereoMatcher_(cv::Ptr<cv::StereoMatcher>* matcher_left) {
		try {
			cv::Ptr<cv::StereoMatcher> ret = cv::ximgproc::createRightMatcher(*matcher_left);
			return Ok(new cv::Ptr<cv::StereoMatcher>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::StereoMatcher>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::StructuredEdgeDetection>*> cv_ximgproc_createStructuredEdgeDetection_const_StringR_Ptr_RFFeatureGetter_(const char* model, const cv::Ptr<cv::ximgproc::RFFeatureGetter>* howToGetFeatures) {
		try {
			cv::Ptr<cv::ximgproc::StructuredEdgeDetection> ret = cv::ximgproc::createStructuredEdgeDetection(cv::String(model), *howToGetFeatures);
			return Ok(new cv::Ptr<cv::ximgproc::StructuredEdgeDetection>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::StructuredEdgeDetection>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::SuperpixelLSC>*> cv_ximgproc_createSuperpixelLSC_const__InputArrayR_int_float(const cv::_InputArray* image, int region_size, float ratio) {
		try {
			cv::Ptr<cv::ximgproc::SuperpixelLSC> ret = cv::ximgproc::createSuperpixelLSC(*image, region_size, ratio);
			return Ok(new cv::Ptr<cv::ximgproc::SuperpixelLSC>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::SuperpixelLSC>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::SuperpixelSEEDS>*> cv_ximgproc_createSuperpixelSEEDS_int_int_int_int_int_int_int_bool(int image_width, int image_height, int image_channels, int num_superpixels, int num_levels, int prior, int histogram_bins, bool double_step) {
		try {
			cv::Ptr<cv::ximgproc::SuperpixelSEEDS> ret = cv::ximgproc::createSuperpixelSEEDS(image_width, image_height, image_channels, num_superpixels, num_levels, prior, histogram_bins, double_step);
			return Ok(new cv::Ptr<cv::ximgproc::SuperpixelSEEDS>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::SuperpixelSEEDS>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::SuperpixelSLIC>*> cv_ximgproc_createSuperpixelSLIC_const__InputArrayR_int_int_float(const cv::_InputArray* image, int algorithm, int region_size, float ruler) {
		try {
			cv::Ptr<cv::ximgproc::SuperpixelSLIC> ret = cv::ximgproc::createSuperpixelSLIC(*image, algorithm, region_size, ruler);
			return Ok(new cv::Ptr<cv::ximgproc::SuperpixelSLIC>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::SuperpixelSLIC>*>))
	}
	
	Result_void cv_ximgproc_dtFilter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_double_double_int_int(const cv::_InputArray* guide, const cv::_InputArray* src, const cv::_OutputArray* dst, double sigmaSpatial, double sigmaColor, int mode, int numIters) {
		try {
			cv::ximgproc::dtFilter(*guide, *src, *dst, sigmaSpatial, sigmaColor, mode, numIters);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_fastGlobalSmootherFilter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_double_double_double_int(const cv::_InputArray* guide, const cv::_InputArray* src, const cv::_OutputArray* dst, double lambda, double sigma_color, double lambda_attenuation, int num_iter) {
		try {
			cv::ximgproc::fastGlobalSmootherFilter(*guide, *src, *dst, lambda, sigma_color, lambda_attenuation, num_iter);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_getDisparityVis_const__InputArrayR_const__OutputArrayR_double(const cv::_InputArray* src, const cv::_OutputArray* dst, double scale) {
		try {
			cv::ximgproc::getDisparityVis(*src, *dst, scale);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_guidedFilter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_int_double_int(const cv::_InputArray* guide, const cv::_InputArray* src, const cv::_OutputArray* dst, int radius, double eps, int dDepth) {
		try {
			cv::ximgproc::guidedFilter(*guide, *src, *dst, radius, eps, dDepth);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_jointBilateralFilter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_int_double_double_int(const cv::_InputArray* joint, const cv::_InputArray* src, const cv::_OutputArray* dst, int d, double sigmaColor, double sigmaSpace, int borderType) {
		try {
			cv::ximgproc::jointBilateralFilter(*joint, *src, *dst, d, sigmaColor, sigmaSpace, borderType);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_l0Smooth_const__InputArrayR_const__OutputArrayR_double_double(const cv::_InputArray* src, const cv::_OutputArray* dst, double lambda, double kappa) {
		try {
			cv::ximgproc::l0Smooth(*src, *dst, lambda, kappa);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_niBlackThreshold_const__InputArrayR_const__OutputArrayR_double_int_int_double(const cv::_InputArray* _src, const cv::_OutputArray* _dst, double maxValue, int type, int blockSize, double delta) {
		try {
			cv::ximgproc::niBlackThreshold(*_src, *_dst, maxValue, type, blockSize, delta);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_readGT_String_const__OutputArrayR(char* src_path, const cv::_OutputArray* dst) {
		try {
			int ret = cv::ximgproc::readGT(cv::String(src_path), *dst);
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_rollingGuidanceFilter_const__InputArrayR_const__OutputArrayR_int_double_double_int_int(const cv::_InputArray* src, const cv::_OutputArray* dst, int d, double sigmaColor, double sigmaSpace, int numOfIter, int borderType) {
		try {
			cv::ximgproc::rollingGuidanceFilter(*src, *dst, d, sigmaColor, sigmaSpace, numOfIter, borderType);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>*> cv_ximgproc_segmentation_createGraphSegmentation_double_float_int(double sigma, float k, int min_size) {
		try {
			cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation> ret = cv::ximgproc::segmentation::createGraphSegmentation(sigma, k, min_size);
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentation() {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentation();
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyColor() {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyColor();
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyFill() {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyFill();
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple() {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple();
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple_Ptr_SelectiveSearchSegmentationStrategy_(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s1) {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple(*s1);
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple_Ptr_SelectiveSearchSegmentationStrategy__Ptr_SelectiveSearchSegmentationStrategy_(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s1, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s2) {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple(*s1, *s2);
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple_Ptr_SelectiveSearchSegmentationStrategy__Ptr_SelectiveSearchSegmentationStrategy__Ptr_SelectiveSearchSegmentationStrategy_(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s1, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s2, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s3) {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple(*s1, *s2, *s3);
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple_Ptr_SelectiveSearchSegmentationStrategy__Ptr_SelectiveSearchSegmentationStrategy__Ptr_SelectiveSearchSegmentationStrategy__Ptr_SelectiveSearchSegmentationStrategy_(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s1, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s2, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s3, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s4) {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple(*s1, *s2, *s3, *s4);
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategySize() {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategySize();
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>*>))
	}
	
	Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>*> cv_ximgproc_segmentation_createSelectiveSearchSegmentationStrategyTexture() {
		try {
			cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture> ret = cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyTexture();
			return Ok(new cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>*>))
	}
	
	Result_void cv_ximgproc_thinning_const__InputArrayR_const__OutputArrayR_int(const cv::_InputArray* src, const cv::_OutputArray* dst, int thinningType) {
		try {
			cv::ximgproc::thinning(*src, *dst, thinningType);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_weightedMedianFilter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_int_double_WMFWeightType_Mat(const cv::_InputArray* joint, const cv::_InputArray* src, const cv::_OutputArray* dst, int r, double sigma, cv::ximgproc::WMFWeightType weightType, cv::Mat* mask) {
		try {
			cv::ximgproc::weightedMedianFilter(*joint, *src, *dst, r, sigma, weightType, *mask);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_filter_const__InputArrayR_const__OutputArrayR_const__InputArrayR(cv::ximgproc::AdaptiveManifoldFilter* instance, const cv::_InputArray* src, const cv::_OutputArray* dst, const cv::_InputArray* joint) {
		try {
			instance->filter(*src, *dst, *joint);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_collectGarbage(cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			instance->collectGarbage();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>*> cv_ximgproc_AdaptiveManifoldFilter_create() {
		try {
			cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter> ret = cv::ximgproc::AdaptiveManifoldFilter::create();
			return Ok(new cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>*>))
	}
	
	Result<double> cv_ximgproc_AdaptiveManifoldFilter_getSigmaS_const(const cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			double ret = instance->getSigmaS();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_setSigmaS_double(cv::ximgproc::AdaptiveManifoldFilter* instance, double val) {
		try {
			instance->setSigmaS(val);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<double> cv_ximgproc_AdaptiveManifoldFilter_getSigmaR_const(const cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			double ret = instance->getSigmaR();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_setSigmaR_double(cv::ximgproc::AdaptiveManifoldFilter* instance, double val) {
		try {
			instance->setSigmaR(val);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_AdaptiveManifoldFilter_getTreeHeight_const(const cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			int ret = instance->getTreeHeight();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_setTreeHeight_int(cv::ximgproc::AdaptiveManifoldFilter* instance, int val) {
		try {
			instance->setTreeHeight(val);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_AdaptiveManifoldFilter_getPCAIterations_const(const cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			int ret = instance->getPCAIterations();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_setPCAIterations_int(cv::ximgproc::AdaptiveManifoldFilter* instance, int val) {
		try {
			instance->setPCAIterations(val);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<bool> cv_ximgproc_AdaptiveManifoldFilter_getAdjustOutliers_const(const cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			bool ret = instance->getAdjustOutliers();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<bool>))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_setAdjustOutliers_bool(cv::ximgproc::AdaptiveManifoldFilter* instance, bool val) {
		try {
			instance->setAdjustOutliers(val);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<bool> cv_ximgproc_AdaptiveManifoldFilter_getUseRNG_const(const cv::ximgproc::AdaptiveManifoldFilter* instance) {
		try {
			bool ret = instance->getUseRNG();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<bool>))
	}
	
	Result_void cv_ximgproc_AdaptiveManifoldFilter_setUseRNG_bool(cv::ximgproc::AdaptiveManifoldFilter* instance, bool val) {
		try {
			instance->setUseRNG(val);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_DTFilter_filter_const__InputArrayR_const__OutputArrayR_int(cv::ximgproc::DTFilter* instance, const cv::_InputArray* src, const cv::_OutputArray* dst, int dDepth) {
		try {
			instance->filter(*src, *dst, dDepth);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_DisparityFilter_filter_const__InputArrayR_const__InputArrayR_const__OutputArrayR_const__InputArrayR_Rect_const__InputArrayR(cv::ximgproc::DisparityFilter* instance, const cv::_InputArray* disparity_map_left, const cv::_InputArray* left_view, const cv::_OutputArray* filtered_disparity_map, const cv::_InputArray* disparity_map_right, const cv::Rect* ROI, const cv::_InputArray* right_view) {
		try {
			instance->filter(*disparity_map_left, *left_view, *filtered_disparity_map, *disparity_map_right, *ROI, *right_view);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<double> cv_ximgproc_DisparityWLSFilter_getLambda(cv::ximgproc::DisparityWLSFilter* instance) {
		try {
			double ret = instance->getLambda();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result_void cv_ximgproc_DisparityWLSFilter_setLambda_double(cv::ximgproc::DisparityWLSFilter* instance, double _lambda) {
		try {
			instance->setLambda(_lambda);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<double> cv_ximgproc_DisparityWLSFilter_getSigmaColor(cv::ximgproc::DisparityWLSFilter* instance) {
		try {
			double ret = instance->getSigmaColor();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result_void cv_ximgproc_DisparityWLSFilter_setSigmaColor_double(cv::ximgproc::DisparityWLSFilter* instance, double _sigma_color) {
		try {
			instance->setSigmaColor(_sigma_color);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_DisparityWLSFilter_getLRCthresh(cv::ximgproc::DisparityWLSFilter* instance) {
		try {
			int ret = instance->getLRCthresh();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_DisparityWLSFilter_setLRCthresh_int(cv::ximgproc::DisparityWLSFilter* instance, int _LRC_thresh) {
		try {
			instance->setLRCthresh(_LRC_thresh);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_DisparityWLSFilter_getDepthDiscontinuityRadius(cv::ximgproc::DisparityWLSFilter* instance) {
		try {
			int ret = instance->getDepthDiscontinuityRadius();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_DisparityWLSFilter_setDepthDiscontinuityRadius_int(cv::ximgproc::DisparityWLSFilter* instance, int _disc_radius) {
		try {
			instance->setDepthDiscontinuityRadius(_disc_radius);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Mat*> cv_ximgproc_DisparityWLSFilter_getConfidenceMap(cv::ximgproc::DisparityWLSFilter* instance) {
		try {
			cv::Mat ret = instance->getConfidenceMap();
			return Ok(new cv::Mat(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Mat*>))
	}
	
	Result<cv::Rect> cv_ximgproc_DisparityWLSFilter_getROI(cv::ximgproc::DisparityWLSFilter* instance) {
		try {
			cv::Rect ret = instance->getROI();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Rect>))
	}
	
	Result_void cv_ximgproc_EdgeAwareInterpolator_setK_int(cv::ximgproc::EdgeAwareInterpolator* instance, int _k) {
		try {
			instance->setK(_k);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_EdgeAwareInterpolator_getK(cv::ximgproc::EdgeAwareInterpolator* instance) {
		try {
			int ret = instance->getK();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_EdgeAwareInterpolator_setSigma_float(cv::ximgproc::EdgeAwareInterpolator* instance, float _sigma) {
		try {
			instance->setSigma(_sigma);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_ximgproc_EdgeAwareInterpolator_getSigma(cv::ximgproc::EdgeAwareInterpolator* instance) {
		try {
			float ret = instance->getSigma();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_ximgproc_EdgeAwareInterpolator_setLambda_float(cv::ximgproc::EdgeAwareInterpolator* instance, float _lambda) {
		try {
			instance->setLambda(_lambda);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_ximgproc_EdgeAwareInterpolator_getLambda(cv::ximgproc::EdgeAwareInterpolator* instance) {
		try {
			float ret = instance->getLambda();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_ximgproc_EdgeAwareInterpolator_setUsePostProcessing_bool(cv::ximgproc::EdgeAwareInterpolator* instance, bool _use_post_proc) {
		try {
			instance->setUsePostProcessing(_use_post_proc);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<bool> cv_ximgproc_EdgeAwareInterpolator_getUsePostProcessing(cv::ximgproc::EdgeAwareInterpolator* instance) {
		try {
			bool ret = instance->getUsePostProcessing();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<bool>))
	}
	
	Result_void cv_ximgproc_EdgeAwareInterpolator_setFGSLambda_float(cv::ximgproc::EdgeAwareInterpolator* instance, float _lambda) {
		try {
			instance->setFGSLambda(_lambda);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_ximgproc_EdgeAwareInterpolator_getFGSLambda(cv::ximgproc::EdgeAwareInterpolator* instance) {
		try {
			float ret = instance->getFGSLambda();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_ximgproc_EdgeAwareInterpolator_setFGSSigma_float(cv::ximgproc::EdgeAwareInterpolator* instance, float _sigma) {
		try {
			instance->setFGSSigma(_sigma);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_ximgproc_EdgeAwareInterpolator_getFGSSigma(cv::ximgproc::EdgeAwareInterpolator* instance) {
		try {
			float ret = instance->getFGSSigma();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_ximgproc_FastGlobalSmootherFilter_filter_const__InputArrayR_const__OutputArrayR(cv::ximgproc::FastGlobalSmootherFilter* instance, const cv::_InputArray* src, const cv::_OutputArray* dst) {
		try {
			instance->filter(*src, *dst);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_FastLineDetector_detect_const__InputArrayR_const__OutputArrayR(cv::ximgproc::FastLineDetector* instance, const cv::_InputArray* _image, const cv::_OutputArray* _lines) {
		try {
			instance->detect(*_image, *_lines);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_FastLineDetector_drawSegments_const__InputOutputArrayR_const__InputArrayR_bool(cv::ximgproc::FastLineDetector* instance, const cv::_InputOutputArray* _image, const cv::_InputArray* lines, bool draw_arrow) {
		try {
			instance->drawSegments(*_image, *lines, draw_arrow);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_GuidedFilter_filter_const__InputArrayR_const__OutputArrayR_int(cv::ximgproc::GuidedFilter* instance, const cv::_InputArray* src, const cv::_OutputArray* dst, int dDepth) {
		try {
			instance->filter(*src, *dst, dDepth);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_RFFeatureGetter_getFeatures_const_const_MatR_MatR_int_int_int_int_int(const cv::ximgproc::RFFeatureGetter* instance, const cv::Mat* src, cv::Mat* features, int gnrmRad, int gsmthRad, int shrink, int outNum, int gradNum) {
		try {
			instance->getFeatures(*src, *features, gnrmRad, gsmthRad, shrink, outNum, gradNum);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SparseMatchInterpolator_interpolate_const__InputArrayR_const__InputArrayR_const__InputArrayR_const__InputArrayR_const__OutputArrayR(cv::ximgproc::SparseMatchInterpolator* instance, const cv::_InputArray* from_image, const cv::_InputArray* from_points, const cv::_InputArray* to_image, const cv::_InputArray* to_points, const cv::_OutputArray* dense_flow) {
		try {
			instance->interpolate(*from_image, *from_points, *to_image, *to_points, *dense_flow);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_StructuredEdgeDetection_detectEdges_const_const_MatR_MatR(const cv::ximgproc::StructuredEdgeDetection* instance, const cv::Mat* src, cv::Mat* dst) {
		try {
			instance->detectEdges(*src, *dst);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_SuperpixelLSC_getNumberOfSuperpixels_const(const cv::ximgproc::SuperpixelLSC* instance) {
		try {
			int ret = instance->getNumberOfSuperpixels();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_SuperpixelLSC_iterate_int(cv::ximgproc::SuperpixelLSC* instance, int num_iterations) {
		try {
			instance->iterate(num_iterations);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelLSC_getLabels_const_const__OutputArrayR(const cv::ximgproc::SuperpixelLSC* instance, const cv::_OutputArray* labels_out) {
		try {
			instance->getLabels(*labels_out);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelLSC_getLabelContourMask_const_const__OutputArrayR_bool(const cv::ximgproc::SuperpixelLSC* instance, const cv::_OutputArray* image, bool thick_line) {
		try {
			instance->getLabelContourMask(*image, thick_line);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelLSC_enforceLabelConnectivity_int(cv::ximgproc::SuperpixelLSC* instance, int min_element_size) {
		try {
			instance->enforceLabelConnectivity(min_element_size);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_SuperpixelSEEDS_getNumberOfSuperpixels(cv::ximgproc::SuperpixelSEEDS* instance) {
		try {
			int ret = instance->getNumberOfSuperpixels();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_SuperpixelSEEDS_iterate_const__InputArrayR_int(cv::ximgproc::SuperpixelSEEDS* instance, const cv::_InputArray* img, int num_iterations) {
		try {
			instance->iterate(*img, num_iterations);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelSEEDS_getLabels_const__OutputArrayR(cv::ximgproc::SuperpixelSEEDS* instance, const cv::_OutputArray* labels_out) {
		try {
			instance->getLabels(*labels_out);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelSEEDS_getLabelContourMask_const__OutputArrayR_bool(cv::ximgproc::SuperpixelSEEDS* instance, const cv::_OutputArray* image, bool thick_line) {
		try {
			instance->getLabelContourMask(*image, thick_line);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_SuperpixelSLIC_getNumberOfSuperpixels_const(const cv::ximgproc::SuperpixelSLIC* instance) {
		try {
			int ret = instance->getNumberOfSuperpixels();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_SuperpixelSLIC_iterate_int(cv::ximgproc::SuperpixelSLIC* instance, int num_iterations) {
		try {
			instance->iterate(num_iterations);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelSLIC_getLabels_const_const__OutputArrayR(const cv::ximgproc::SuperpixelSLIC* instance, const cv::_OutputArray* labels_out) {
		try {
			instance->getLabels(*labels_out);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelSLIC_getLabelContourMask_const_const__OutputArrayR_bool(const cv::ximgproc::SuperpixelSLIC* instance, const cv::_OutputArray* image, bool thick_line) {
		try {
			instance->getLabelContourMask(*image, thick_line);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_SuperpixelSLIC_enforceLabelConnectivity_int(cv::ximgproc::SuperpixelSLIC* instance, int min_element_size) {
		try {
			instance->enforceLabelConnectivity(min_element_size);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_GraphSegmentation_processImage_const__InputArrayR_const__OutputArrayR(cv::ximgproc::segmentation::GraphSegmentation* instance, const cv::_InputArray* src, const cv::_OutputArray* dst) {
		try {
			instance->processImage(*src, *dst);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_GraphSegmentation_setSigma_double(cv::ximgproc::segmentation::GraphSegmentation* instance, double sigma) {
		try {
			instance->setSigma(sigma);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<double> cv_ximgproc_segmentation_GraphSegmentation_getSigma(cv::ximgproc::segmentation::GraphSegmentation* instance) {
		try {
			double ret = instance->getSigma();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<double>))
	}
	
	Result_void cv_ximgproc_segmentation_GraphSegmentation_setK_float(cv::ximgproc::segmentation::GraphSegmentation* instance, float k) {
		try {
			instance->setK(k);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_ximgproc_segmentation_GraphSegmentation_getK(cv::ximgproc::segmentation::GraphSegmentation* instance) {
		try {
			float ret = instance->getK();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_ximgproc_segmentation_GraphSegmentation_setMinSize_int(cv::ximgproc::segmentation::GraphSegmentation* instance, int min_size) {
		try {
			instance->setMinSize(min_size);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_ximgproc_segmentation_GraphSegmentation_getMinSize(cv::ximgproc::segmentation::GraphSegmentation* instance) {
		try {
			int ret = instance->getMinSize();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_setBaseImage_const__InputArrayR(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, const cv::_InputArray* img) {
		try {
			instance->setBaseImage(*img);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_switchToSingleStrategy_int_float(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, int k, float sigma) {
		try {
			instance->switchToSingleStrategy(k, sigma);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_switchToSelectiveSearchFast_int_int_float(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, int base_k, int inc_k, float sigma) {
		try {
			instance->switchToSelectiveSearchFast(base_k, inc_k, sigma);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_switchToSelectiveSearchQuality_int_int_float(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, int base_k, int inc_k, float sigma) {
		try {
			instance->switchToSelectiveSearchQuality(base_k, inc_k, sigma);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_addImage_const__InputArrayR(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, const cv::_InputArray* img) {
		try {
			instance->addImage(*img);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_clearImages(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance) {
		try {
			instance->clearImages();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_addGraphSegmentation_Ptr_GraphSegmentation_(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>* g) {
		try {
			instance->addGraphSegmentation(*g);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_clearGraphSegmentations(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance) {
		try {
			instance->clearGraphSegmentations();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_addStrategy_Ptr_SelectiveSearchSegmentationStrategy_(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* s) {
		try {
			instance->addStrategy(*s);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_clearStrategies(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance) {
		try {
			instance->clearStrategies();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentation_process_vector_Rect_R(cv::ximgproc::segmentation::SelectiveSearchSegmentation* instance, std::vector<cv::Rect>* rects) {
		try {
			instance->process(*rects);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentationStrategy_setImage_const__InputArrayR_const__InputArrayR_const__InputArrayR_int(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy* instance, const cv::_InputArray* img, const cv::_InputArray* regions, const cv::_InputArray* sizes, int image_id) {
		try {
			instance->setImage(*img, *regions, *sizes, image_id);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_ximgproc_segmentation_SelectiveSearchSegmentationStrategy_get_int_int(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy* instance, int r1, int r2) {
		try {
			float ret = instance->get(r1, r2);
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentationStrategy_merge_int_int(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy* instance, int r1, int r2) {
		try {
			instance->merge(r1, r2);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentationStrategyMultiple_addStrategy_Ptr_SelectiveSearchSegmentationStrategy__float(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple* instance, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>* g, float weight) {
		try {
			instance->addStrategy(*g, weight);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_ximgproc_segmentation_SelectiveSearchSegmentationStrategyMultiple_clearStrategies(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple* instance) {
		try {
			instance->clearStrategies();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
}
