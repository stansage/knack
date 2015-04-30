#pragma once

namespace knack {

//! Класс цели
class Target
{
public:
    //! Структура цвета
    struct Color
    {
        float red;
        float green;
        float blue;
    };

    //! Создает цель с указанным диапазоном радиуса, пределом скорости и награды
    Target( float radiusMin, float radiusMax, float speedMax, int rewardMax );

    //! Возвращает цвет
    Color getColor() const;
    //! Возвращает радиус
    float getRadius() const;
    //! Возвращает награду
    int getReward() const;
    //! Возвращает X-координату центра
    float getX() const;
    //! Возвращает Y-координату центра
    float getY() const;

    //! Проверяет вхождение точки c указанными кооринатами в область цели
    bool inArea( float x, float y ) const;
    //! Проверяет выход цели за границы рабочей области
    bool inBounds() const;

    //! Меняет расположение цели
    void move();

private:
    //! Генерирует случайное число от 0 до 1
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
