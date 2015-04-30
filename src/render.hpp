#pragma once

#include <string>

namespace knack {

class Font;

//! Класс рендера
class Render
{
public:
    //! Создает рендер
    Render();

    //! Подготавливает область с указанной шириной и высотой для рендеринга
    void begin( int width, int height );
    //! Завершает рендеринг
    void end();

    //! Устанавливает цвет рисования с указанными значениями красного, зеленого и синего
    void useColor( float r, float g, float b );
    //! Рисует диск с указанными координатами, радиуса и количеством сегментов
    void drawDisk( float x, float y, float r, int segments );
    //! Рисует текст с указанными координатами, шрифта и строки символов
    void drawText(float x, float y, const Font & font, const std::string & text );
};

} // namespace knack
