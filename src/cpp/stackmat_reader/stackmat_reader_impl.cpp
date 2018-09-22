#include <iostream>
#include "stackmat_reader_impl.hpp"
#include "stackmat.hpp"

namespace pro_timer {
    
    using namespace std;

    std::shared_ptr<StackmatReader> StackmatReader::instance(float sample_rate) {
        return std::make_shared<StackmatReaderImpl>(sample_rate);
    }

    StackmatReaderImpl::StackmatReaderImpl(float sample_rate) {
        reader = new stackmatReader(sample_rate);
    }

    int32_t StackmatReaderImpl::proc_signal(const std::vector<float> & signals, int32_t length) {
        float *arr = const_cast<float *>(signals.data());
        return this->reader->proc_signal(arr, length);
    }

    int32_t StackmatReaderImpl::get_time() {
        return this->reader->get_time();
    }

    int32_t StackmatReaderImpl::get_status() {
        return this->reader->get_status();
    }
}
