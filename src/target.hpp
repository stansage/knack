#pragma once

namespace knack {

class Target
{
public:
    struct Color
    {
        float red;
        float green;
        float blue;
    };

    Target(float radiusMin, float radiusMax, float speedMax, int rewardMax );

    Color getColor() const;
    float getRadius() const;
    int getReward() const;
    float getX() const;
    float getY() const;

    bool inArea( float x, float y ) const;
    bool move();

private:
    static float getRandomValue();

private:
    Color m_color;
    float m_radius;
    int m_reward;
    float m_speed;
    float m_x;
    float m_y;
};

} // namespace knack
