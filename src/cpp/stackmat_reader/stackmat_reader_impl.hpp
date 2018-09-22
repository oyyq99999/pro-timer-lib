#pragma once

#include "stackmat_reader.hpp"
#include "stackmat.hpp"

namespace pro_timer {

    class StackmatReaderImpl : public StackmatReader {

    public:

        StackmatReaderImpl(float sample_rate);

        int32_t proc_signal(const std::vector<float> & signals, int32_t length);

        int32_t get_time();

        int32_t get_status();

    private:

        stackmatReader *reader;
    };
}
