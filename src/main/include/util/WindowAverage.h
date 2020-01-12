#pragma once

#include <wpi/circular_buffer.h>
#include <functional>
#include <numeric>

namespace frc4065
{

template <class T>
class WindowAverage
{
public:
    explicit WindowAverage(size_t window_size);
    size_t size() const;
    double avg() const;
    void add(T value);
private:
    const size_t length_;
    wpi::circular_buffer<T> cbuffer_;
};

}