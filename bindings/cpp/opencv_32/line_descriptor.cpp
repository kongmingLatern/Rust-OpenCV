#include "common.hpp"
#include <opencv2/line_descriptor.hpp>
#include "line_descriptor_types.hpp"

extern "C" {
	Result_void cv_line_descriptor_drawKeylines_const_MatR_const_vector_KeyLine_R_MatR_const_ScalarR_int(const cv::Mat* image, const std::vector<cv::line_descriptor::KeyLine>* keylines, cv::Mat* outImage, const cv::Scalar* color, int flags) {
		try {
			cv::line_descriptor::drawKeylines(*image, *keylines, *outImage, *color, flags);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_drawLineMatches_const_MatR_const_vector_KeyLine_R_const_MatR_const_vector_KeyLine_R_const_vector_DMatch_R_MatR_const_ScalarR_const_ScalarR_const_vector_char_R_int(const cv::Mat* img1, const std::vector<cv::line_descriptor::KeyLine>* keylines1, const cv::Mat* img2, const std::vector<cv::line_descriptor::KeyLine>* keylines2, const std::vector<cv::DMatch>* matches1to2, cv::Mat* outImg, const cv::Scalar* matchColor, const cv::Scalar* singleLineColor, const std::vector<char>* matchesMask, int flags) {
		try {
			cv::line_descriptor::drawLineMatches(*img1, *keylines1, *img2, *keylines2, *matches1to2, *outImg, *matchColor, *singleLineColor, *matchesMask, flags);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	void cv_BinaryDescriptor_delete(cv::line_descriptor::BinaryDescriptor* instance) {
		delete instance;
	}
	Result<cv::line_descriptor::BinaryDescriptor*> cv_line_descriptor_BinaryDescriptor_BinaryDescriptor_const_ParamsR(const cv::line_descriptor::BinaryDescriptor::Params* parameters) {
		try {
			cv::line_descriptor::BinaryDescriptor* ret = new cv::line_descriptor::BinaryDescriptor(*parameters);
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::line_descriptor::BinaryDescriptor*>))
	}
	
	Result<cv::Ptr<cv::line_descriptor::BinaryDescriptor>*> cv_line_descriptor_BinaryDescriptor_createBinaryDescriptor() {
		try {
			cv::Ptr<cv::line_descriptor::BinaryDescriptor> ret = cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor();
			return Ok(new cv::Ptr<cv::line_descriptor::BinaryDescriptor>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::line_descriptor::BinaryDescriptor>*>))
	}
	
	Result<cv::Ptr<cv::line_descriptor::BinaryDescriptor>*> cv_line_descriptor_BinaryDescriptor_createBinaryDescriptor_Params(cv::line_descriptor::BinaryDescriptor::Params* parameters) {
		try {
			cv::Ptr<cv::line_descriptor::BinaryDescriptor> ret = cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor(*parameters);
			return Ok(new cv::Ptr<cv::line_descriptor::BinaryDescriptor>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::line_descriptor::BinaryDescriptor>*>))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_getNumOfOctaves(cv::line_descriptor::BinaryDescriptor* instance) {
		try {
			int ret = instance->getNumOfOctaves();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_setNumOfOctaves_int(cv::line_descriptor::BinaryDescriptor* instance, int octaves) {
		try {
			instance->setNumOfOctaves(octaves);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_getWidthOfBand(cv::line_descriptor::BinaryDescriptor* instance) {
		try {
			int ret = instance->getWidthOfBand();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_setWidthOfBand_int(cv::line_descriptor::BinaryDescriptor* instance, int width) {
		try {
			instance->setWidthOfBand(width);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_getReductionRatio(cv::line_descriptor::BinaryDescriptor* instance) {
		try {
			int ret = instance->getReductionRatio();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_setReductionRatio_int(cv::line_descriptor::BinaryDescriptor* instance, int rRatio) {
		try {
			instance->setReductionRatio(rRatio);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_read_const_FileNodeR(cv::line_descriptor::BinaryDescriptor* instance, const cv::FileNode* fn) {
		try {
			instance->read(*fn);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_write_const_FileStorageR(const cv::line_descriptor::BinaryDescriptor* instance, cv::FileStorage* fs) {
		try {
			instance->write(*fs);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_detect_const_MatR_vector_KeyLine_R_const_MatR(cv::line_descriptor::BinaryDescriptor* instance, const cv::Mat* image, std::vector<cv::line_descriptor::KeyLine>* keypoints, const cv::Mat* mask) {
		try {
			instance->detect(*image, *keypoints, *mask);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_detect_const_const_vector_Mat_R_vector_vector_KeyLine__R_const_vector_Mat_R(const cv::line_descriptor::BinaryDescriptor* instance, const std::vector<cv::Mat>* images, std::vector<std::vector<cv::line_descriptor::KeyLine>>* keylines, const std::vector<cv::Mat>* masks) {
		try {
			instance->detect(*images, *keylines, *masks);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_compute_const_const_MatR_vector_KeyLine_R_MatR_bool(const cv::line_descriptor::BinaryDescriptor* instance, const cv::Mat* image, std::vector<cv::line_descriptor::KeyLine>* keylines, cv::Mat* descriptors, bool returnFloatDescr) {
		try {
			instance->compute(*image, *keylines, *descriptors, returnFloatDescr);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_compute_const_const_vector_Mat_R_vector_vector_KeyLine__R_vector_Mat_R_bool(const cv::line_descriptor::BinaryDescriptor* instance, const std::vector<cv::Mat>* images, std::vector<std::vector<cv::line_descriptor::KeyLine>>* keylines, std::vector<cv::Mat>* descriptors, bool returnFloatDescr) {
		try {
			instance->compute(*images, *keylines, *descriptors, returnFloatDescr);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_descriptorSize_const(const cv::line_descriptor::BinaryDescriptor* instance) {
		try {
			int ret = instance->descriptorSize();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_descriptorType_const(const cv::line_descriptor::BinaryDescriptor* instance) {
		try {
			int ret = instance->descriptorType();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_defaultNorm_const(const cv::line_descriptor::BinaryDescriptor* instance) {
		try {
			int ret = instance->defaultNorm();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_Params_getPropNumOfOctave__const(const cv::line_descriptor::BinaryDescriptor::Params* instance) {
		try {
			int ret = instance->numOfOctave_;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_Params_setPropNumOfOctave__int(cv::line_descriptor::BinaryDescriptor::Params* instance, int val) {
		try {
			instance->numOfOctave_ = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_Params_getPropWidthOfBand__const(const cv::line_descriptor::BinaryDescriptor::Params* instance) {
		try {
			int ret = instance->widthOfBand_;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_Params_setPropWidthOfBand__int(cv::line_descriptor::BinaryDescriptor::Params* instance, int val) {
		try {
			instance->widthOfBand_ = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_Params_getPropReductionRatio_const(const cv::line_descriptor::BinaryDescriptor::Params* instance) {
		try {
			int ret = instance->reductionRatio;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_Params_setPropReductionRatio_int(cv::line_descriptor::BinaryDescriptor::Params* instance, int val) {
		try {
			instance->reductionRatio = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_BinaryDescriptor_Params_getPropKsize__const(const cv::line_descriptor::BinaryDescriptor::Params* instance) {
		try {
			int ret = instance->ksize_;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_Params_setPropKsize__int(cv::line_descriptor::BinaryDescriptor::Params* instance, int val) {
		try {
			instance->ksize_ = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	void cv_BinaryDescriptor_Params_delete(cv::line_descriptor::BinaryDescriptor::Params* instance) {
		delete instance;
	}
	Result<cv::line_descriptor::BinaryDescriptor::Params*> cv_line_descriptor_BinaryDescriptor_Params_Params() {
		try {
			cv::line_descriptor::BinaryDescriptor::Params* ret = new cv::line_descriptor::BinaryDescriptor::Params();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::line_descriptor::BinaryDescriptor::Params*>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_Params_read_const_FileNodeR(cv::line_descriptor::BinaryDescriptor::Params* instance, const cv::FileNode* fn) {
		try {
			instance->read(*fn);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptor_Params_write_const_FileStorageR(const cv::line_descriptor::BinaryDescriptor::Params* instance, cv::FileStorage* fs) {
		try {
			instance->write(*fs);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	void cv_BinaryDescriptorMatcher_delete(cv::line_descriptor::BinaryDescriptorMatcher* instance) {
		delete instance;
	}
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_match_const_const_MatR_const_MatR_vector_DMatch_R_const_MatR(const cv::line_descriptor::BinaryDescriptorMatcher* instance, const cv::Mat* queryDescriptors, const cv::Mat* trainDescriptors, std::vector<cv::DMatch>* matches, const cv::Mat* mask) {
		try {
			instance->match(*queryDescriptors, *trainDescriptors, *matches, *mask);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_match_const_MatR_vector_DMatch_R_const_vector_Mat_R(cv::line_descriptor::BinaryDescriptorMatcher* instance, const cv::Mat* queryDescriptors, std::vector<cv::DMatch>* matches, const std::vector<cv::Mat>* masks) {
		try {
			instance->match(*queryDescriptors, *matches, *masks);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_knnMatch_const_const_MatR_const_MatR_vector_vector_DMatch__R_int_const_MatR_bool(const cv::line_descriptor::BinaryDescriptorMatcher* instance, const cv::Mat* queryDescriptors, const cv::Mat* trainDescriptors, std::vector<std::vector<cv::DMatch>>* matches, int k, const cv::Mat* mask, bool compactResult) {
		try {
			instance->knnMatch(*queryDescriptors, *trainDescriptors, *matches, k, *mask, compactResult);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_knnMatch_const_MatR_vector_vector_DMatch__R_int_const_vector_Mat_R_bool(cv::line_descriptor::BinaryDescriptorMatcher* instance, const cv::Mat* queryDescriptors, std::vector<std::vector<cv::DMatch>>* matches, int k, const std::vector<cv::Mat>* masks, bool compactResult) {
		try {
			instance->knnMatch(*queryDescriptors, *matches, k, *masks, compactResult);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_radiusMatch_const_const_MatR_const_MatR_vector_vector_DMatch__R_float_const_MatR_bool(const cv::line_descriptor::BinaryDescriptorMatcher* instance, const cv::Mat* queryDescriptors, const cv::Mat* trainDescriptors, std::vector<std::vector<cv::DMatch>>* matches, float maxDistance, const cv::Mat* mask, bool compactResult) {
		try {
			instance->radiusMatch(*queryDescriptors, *trainDescriptors, *matches, maxDistance, *mask, compactResult);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_radiusMatch_const_MatR_vector_vector_DMatch__R_float_const_vector_Mat_R_bool(cv::line_descriptor::BinaryDescriptorMatcher* instance, const cv::Mat* queryDescriptors, std::vector<std::vector<cv::DMatch>>* matches, float maxDistance, const std::vector<cv::Mat>* masks, bool compactResult) {
		try {
			instance->radiusMatch(*queryDescriptors, *matches, maxDistance, *masks, compactResult);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_add_const_vector_Mat_R(cv::line_descriptor::BinaryDescriptorMatcher* instance, const std::vector<cv::Mat>* descriptors) {
		try {
			instance->add(*descriptors);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_train(cv::line_descriptor::BinaryDescriptorMatcher* instance) {
		try {
			instance->train();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Ptr<cv::line_descriptor::BinaryDescriptorMatcher>*> cv_line_descriptor_BinaryDescriptorMatcher_createBinaryDescriptorMatcher() {
		try {
			cv::Ptr<cv::line_descriptor::BinaryDescriptorMatcher> ret = cv::line_descriptor::BinaryDescriptorMatcher::createBinaryDescriptorMatcher();
			return Ok(new cv::Ptr<cv::line_descriptor::BinaryDescriptorMatcher>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::line_descriptor::BinaryDescriptorMatcher>*>))
	}
	
	Result_void cv_line_descriptor_BinaryDescriptorMatcher_clear(cv::line_descriptor::BinaryDescriptorMatcher* instance) {
		try {
			instance->clear();
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::line_descriptor::BinaryDescriptorMatcher*> cv_line_descriptor_BinaryDescriptorMatcher_BinaryDescriptorMatcher() {
		try {
			cv::line_descriptor::BinaryDescriptorMatcher* ret = new cv::line_descriptor::BinaryDescriptorMatcher();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::line_descriptor::BinaryDescriptorMatcher*>))
	}
	
	void cv_DrawLinesMatchesFlags_delete(cv::line_descriptor::DrawLinesMatchesFlags* instance) {
		delete instance;
	}
	Result<float> cv_line_descriptor_KeyLine_getPropAngle_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->angle;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropAngle_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->angle = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_KeyLine_getPropClass_id_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			int ret = instance->class_id;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropClass_id_int(cv::line_descriptor::KeyLine* instance, int val) {
		try {
			instance->class_id = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_KeyLine_getPropOctave_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			int ret = instance->octave;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropOctave_int(cv::line_descriptor::KeyLine* instance, int val) {
		try {
			instance->octave = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<cv::Point2f> cv_line_descriptor_KeyLine_getPropPt_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			cv::Point2f ret = instance->pt;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Point2f>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropPt_Point2f(cv::line_descriptor::KeyLine* instance, const cv::Point2f* val) {
		try {
			instance->pt = *val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropResponse_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->response;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropResponse_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->response = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropSize_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->size;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropSize_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->size = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropStartPointX_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->startPointX;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropStartPointX_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->startPointX = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropStartPointY_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->startPointY;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropStartPointY_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->startPointY = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropEndPointX_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->endPointX;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropEndPointX_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->endPointX = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropEndPointY_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->endPointY;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropEndPointY_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->endPointY = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropSPointInOctaveX_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->sPointInOctaveX;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropSPointInOctaveX_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->sPointInOctaveX = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropSPointInOctaveY_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->sPointInOctaveY;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropSPointInOctaveY_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->sPointInOctaveY = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropEPointInOctaveX_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->ePointInOctaveX;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropEPointInOctaveX_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->ePointInOctaveX = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropEPointInOctaveY_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->ePointInOctaveY;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropEPointInOctaveY_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->ePointInOctaveY = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<float> cv_line_descriptor_KeyLine_getPropLineLength_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			float ret = instance->lineLength;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<float>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropLineLength_float(cv::line_descriptor::KeyLine* instance, float val) {
		try {
			instance->lineLength = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result<int> cv_line_descriptor_KeyLine_getPropNumOfPixels_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			int ret = instance->numOfPixels;
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<int>))
	}
	
	Result_void cv_line_descriptor_KeyLine_setPropNumOfPixels_int(cv::line_descriptor::KeyLine* instance, int val) {
		try {
			instance->numOfPixels = val;
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	void cv_KeyLine_delete(cv::line_descriptor::KeyLine* instance) {
		delete instance;
	}
	Result<cv::Point2f> cv_line_descriptor_KeyLine_getStartPoint_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			cv::Point2f ret = instance->getStartPoint();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Point2f>))
	}
	
	Result<cv::Point2f> cv_line_descriptor_KeyLine_getEndPoint_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			cv::Point2f ret = instance->getEndPoint();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Point2f>))
	}
	
	Result<cv::Point2f> cv_line_descriptor_KeyLine_getStartPointInOctave_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			cv::Point2f ret = instance->getStartPointInOctave();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Point2f>))
	}
	
	Result<cv::Point2f> cv_line_descriptor_KeyLine_getEndPointInOctave_const(const cv::line_descriptor::KeyLine* instance) {
		try {
			cv::Point2f ret = instance->getEndPointInOctave();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Point2f>))
	}
	
	Result<cv::line_descriptor::KeyLine*> cv_line_descriptor_KeyLine_KeyLine() {
		try {
			cv::line_descriptor::KeyLine* ret = new cv::line_descriptor::KeyLine();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::line_descriptor::KeyLine*>))
	}
	
	void cv_LSDDetector_delete(cv::line_descriptor::LSDDetector* instance) {
		delete instance;
	}
	Result<cv::line_descriptor::LSDDetector*> cv_line_descriptor_LSDDetector_LSDDetector() {
		try {
			cv::line_descriptor::LSDDetector* ret = new cv::line_descriptor::LSDDetector();
			return Ok(ret);
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::line_descriptor::LSDDetector*>))
	}
	
	Result<cv::Ptr<cv::line_descriptor::LSDDetector>*> cv_line_descriptor_LSDDetector_createLSDDetector() {
		try {
			cv::Ptr<cv::line_descriptor::LSDDetector> ret = cv::line_descriptor::LSDDetector::createLSDDetector();
			return Ok(new cv::Ptr<cv::line_descriptor::LSDDetector>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::line_descriptor::LSDDetector>*>))
	}
	
	Result_void cv_line_descriptor_LSDDetector_detect_const_MatR_vector_KeyLine_R_int_int_const_MatR(cv::line_descriptor::LSDDetector* instance, const cv::Mat* image, std::vector<cv::line_descriptor::KeyLine>* keypoints, int scale, int numOctaves, const cv::Mat* mask) {
		try {
			instance->detect(*image, *keypoints, scale, numOctaves, *mask);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_line_descriptor_LSDDetector_detect_const_const_vector_Mat_R_vector_vector_KeyLine__R_int_int_const_vector_Mat_R(const cv::line_descriptor::LSDDetector* instance, const std::vector<cv::Mat>* images, std::vector<std::vector<cv::line_descriptor::KeyLine>>* keylines, int scale, int numOctaves, const std::vector<cv::Mat>* masks) {
		try {
			instance->detect(*images, *keylines, scale, numOctaves, *masks);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
}
