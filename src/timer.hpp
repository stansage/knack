#pragma once

#include <chrono>

namespace knack {

class Timer
{
    using Clock = std::chrono::steady_clock;
public:
    Timer();

    int getDuration() const;

    void reset();

    static int64_t now();

private:
    Clock::time_point m_time;
};

} // namespace knack
