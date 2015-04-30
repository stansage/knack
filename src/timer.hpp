#pragma once

#include <chrono>

namespace knack {

//! Класс таймера
class Timer
{
    using Clock = std::chrono::steady_clock;

public:
    //! Создает таймер
    Timer();

    //! Возвращает количество микросекунд с момента сброса таймера
    int getDuration() const;

    //! Сбрасывает таймер в начальное состояние
    void reset();

    //! Получает текущее время эпохи UNIX в секундах
    static int64_t now();

private:
    Clock::time_point m_time;
};

} // namespace knack
