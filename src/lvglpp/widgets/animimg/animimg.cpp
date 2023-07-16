/** \file animimg.cpp
 *  \brief Implementation file for C++ wrapper for lv_animimg_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "animimg.h"
#if LV_USE_ANIMIMG != 0

namespace lvgl::widgets {

    void AnimatedImage::set_src(const std::vector<ImageDescriptor> & imgs) {
        this->dsc = std::make_unique<const lv_img_dsc_t*[]>(imgs.size());
        for (size_t n=0; n<imgs.size(); n++) {
            this->dsc[n] = imgs[n].raw_ptr();
        }
        lv_animimg_set_src(this->raw_ptr(), reinterpret_cast<const void **>(this->dsc.get()), imgs.size());
    }

    void AnimatedImage::start() {
        lv_animimg_start(this->raw_ptr());
    }

    void AnimatedImage::set_duration(uint32_t duration) {
        lv_animimg_set_duration(this->raw_ptr(), duration);
    }

    void AnimatedImage::set_repeat_count(uint16_t count) {
        lv_animimg_set_repeat_count(this->raw_ptr(), count);
    }
}
#endif // LV_USE_ANIMIMG