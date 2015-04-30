#include "timer.hpp"
#include "assert.h"

namespace knack {

Timer::Timer()
{
    reset();
}

int Timer::getDuration() const
{
    auto duration = Clock::now() - m_time;
    auto result = std::chrono::duration_cast< std::chrono::microseconds >( duration ).count();

    if ( result == 0 ) {
        //! Минимальный временной промежуток 1 микросекунда
        result = 1;
    }

    return result;
}

void Timer::reset()
{
    m_time = Clock::now();
}

int64_t Timer::now()
{
    return Clock::now().time_since_epoch().count();
}

} // namespace knack
