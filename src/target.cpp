#include "target.hpp"
#include "timer.hpp"
#include <random>
#include <functional>

namespace knack {

Target::Target( float radiusMin, float radiusMax, float speedMax , int rewardMax )
{
    //! Определяем параметры цели
    m_radius = radiusMin + radiusMax * getRandomValue();
    m_x = -1.f + m_radius + 2.f * ( 1.f - m_radius ) * getRandomValue();
    m_y = 1.f + 2.f * m_radius;
    m_speed = speedMax / m_radius;
    m_reward = rewardMax / m_radius;

    //! Цвет не дожен быть черным
    m_color.red = 0.1 + 0.9 * getRandomValue();
    m_color.green = 0.1 + 0.9 * getRandomValue();
    m_color.blue = 0.1 + 0.9 * getRandomValue();
}

Target::Color Target::getColor() const
{
    return std::move( m_color );
}

float Target::getRadius() const
{
    return m_radius;
}

int Target::getReward() const
{
    return m_reward;
}

float Target::getX() const
{
    return m_x;
}

float Target::getY() const
{
    return m_y;
}

bool Target::inArea( float x, float y ) const
{
    //! Расчет по формуле окружности: X ^ 2 + Y ^ 2 = R ^ 2
    const auto dX = ( m_x - x );
    const auto dY = ( m_y - y );

    return dX * dX + dY * dY < m_radius * m_radius;
}

bool Target::inBounds() const
{
    return m_y > -1.f - m_radius;
}

void Target::move()
{
    m_y -= m_speed;
}

float Target::getRandomValue()
{
    const auto max = std::numeric_limits< int >::max();

    std::uniform_int_distribution< int > distribution( 1, max );
    std::default_random_engine generator( Timer::now() );
    auto random = std::bind( distribution, generator );

    return 1.f * random() / max;
}

} // namespace knack
