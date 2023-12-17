#pragma once

#include <array>
#include <stdlib.h>

#ifndef real_t
typedef float real_t;
#endif

namespace numpy
{

class array{
    real_t* ptr;
    size_t row;
    size_t col;
    bool own_buffer;

public:

    array(size_t r_, size_t c_, real_t* p_=nullptr) : row(r_), col(c_)
    {
        if(p_ == nullptr) {
            ptr = new real_t[row*col];
            own_buffer = true;
        } else {
            ptr = p_;
            own_buffer = false;
        }
    }

    array(const array& arr) : row(arr.row), col(arr.col)
    {
        ptr = new real_t[row * col];
        own_buffer = true;
        for (size_t i = 0; i < row * col; i++)
        {
            ptr[i] = arr.ptr[i];
        }
    }


    ~array() {
        if(own_buffer) {
            delete[] ptr;
        }
    }

    std::array<size_t, 2> shape () const {
        return {row, col};
    }

    real_t* operator[] (size_t row_) {
        return ptr + row_ * col;
    }

};

}
