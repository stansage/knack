#pragma once

#include <vector>

namespace knack {

//! Класс шрифта
class Font
{
    using Point = std::pair< float, float >;
    using Glyph = std::vector< Point >;

public:
    //! Создает шрифт с указанным размером
    Font( float size );

    //! Возвращает размер шрифта
    float getSize() const;

    //! Возвращает глиф для указанного символа
    Glyph findGlyph( char character ) const;

private:
    float m_size;
    std::vector< Glyph > m_glyphs;
};

} // namespace knack
