#pragma once

#include "numpy.h"

namespace signal
{

enum class butter_type {low, high, band, bandstop};
enum class butter_output {ba, sos, zpk};

numpy::array butter(const size_t order, const real_t fc, const real_t fs,
                    butter_type type = butter_type::low,
                    butter_output output = butter_output::ba);

numpy::array butter(const size_t order, const std::array<real_t, 2> fc, const real_t fs,
                    butter_type type = butter_type::band,
                    butter_output output = butter_output::ba);

void sosfilt(const numpy::array &sos, const numpy::array &x, numpy::array &y, numpy::array &zi);

}
