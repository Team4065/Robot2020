#include "util/WindowAverage.h"

// UNTESTED

namespace frc4065
{

template <class T>
WindowAverage<T>::WindowAverage(size_t window_size)
: length_(window_size), cbuffer_({window_size}) {}

template <class T>
void WindowAverage<T>::add(T value)
{

}

template <class T>
size_t WindowAverage<T>::size() const
{
    return length_;
}

template <class T>
double WindowAverage<T>::avg() const
{
    double sum = 0;
    for (int i = 0; i < length_; ++i)
        sum += cbuffer_[i];
    return sum / length_;
}


}