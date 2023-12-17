#include "filter.h"

numpy::array signal::butter(const size_t order, const real_t fc, const real_t fs,
                            signal::butter_type type,
                            signal::butter_output output)
{

}

numpy::array signal::butter(const size_t order, const std::array<real_t, 2> fc, const real_t fs,
                            signal::butter_type type,
                            signal::butter_output output)
{

}

void signal::sosfilt(const numpy::array &sos, const numpy::array &x, numpy::array &y, numpy::array &zi)
{

}
