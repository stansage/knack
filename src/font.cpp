#include "font.hpp"
#include "assert.h"

namespace knack {

Font::Font( float size ) :
    m_size( size ),
    m_glyphs( 10 )
{
    //! Определяем отступ по оси X
    const auto margin = size * 0.2f;

    //! Создаем шрифт вручную, задавая координаты точек для каждого глифа
    m_glyphs[ 0 ].push_back( std::make_pair( margin, 0 ) );
    m_glyphs[ 0 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 0 ].push_back( std::make_pair( size , size ) );
    m_glyphs[ 0 ].push_back( std::make_pair( size , 0 ) );
    m_glyphs[ 0 ].push_back( std::make_pair( margin , 0 ) );

    m_glyphs[ 1 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 1 ].push_back( std::make_pair( margin + ( size - margin ) / 2, size ) );
    m_glyphs[ 1 ].push_back( std::make_pair( margin + ( size - margin ) / 2, 0 ) );
    m_glyphs[ 1 ].push_back( std::make_pair( margin, 0 ) );
    m_glyphs[ 1 ].push_back( std::make_pair( size, 0 ) );

    m_glyphs[ 2 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 2 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 2 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 2 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 2 ].push_back( std::make_pair( margin, 0 ) );
    m_glyphs[ 2 ].push_back( std::make_pair( size, 0 ) );

    m_glyphs[ 3 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 3 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 3 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 3 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 3 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 3 ].push_back( std::make_pair( size, 0 ) );
    m_glyphs[ 3 ].push_back( std::make_pair( margin, 0 ) );

    m_glyphs[ 4 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 4 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 4 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 4 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 4 ].push_back( std::make_pair( size, 0 ) );

    m_glyphs[ 5 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 5 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 5 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 5 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 5 ].push_back( std::make_pair( size, 0 ) );
    m_glyphs[ 5 ].push_back( std::make_pair( margin, 0 ) );

    m_glyphs[ 6 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 6 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 6 ].push_back( std::make_pair( margin, 0 ) );
    m_glyphs[ 6 ].push_back( std::make_pair( size, 0 ) );
    m_glyphs[ 6 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 6 ].push_back( std::make_pair( margin, size / 2 ) );

    m_glyphs[ 7 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 7 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 7 ].push_back( std::make_pair( size / 2, 0 ) );

    m_glyphs[ 8 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 8 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 8 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 8 ].push_back( std::make_pair( size, size / 2 ) );
    m_glyphs[ 8 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 8 ].push_back( std::make_pair( margin, 0 ) );
    m_glyphs[ 8 ].push_back( std::make_pair( size, 0 ) );
    m_glyphs[ 8 ].push_back( std::make_pair( size, size / 2 ) );

    m_glyphs[ 9 ].push_back( std::make_pair( margin, 0.0 ) );
    m_glyphs[ 9 ].push_back( std::make_pair( size, 0.0 ) );
    m_glyphs[ 9 ].push_back( std::make_pair( size, size ) );
    m_glyphs[ 9 ].push_back( std::make_pair( margin, size ) );
    m_glyphs[ 9 ].push_back( std::make_pair( margin, size / 2 ) );
    m_glyphs[ 9 ].push_back( std::make_pair( size, size / 2 ) );
}

float Font::getSize() const
{
    return m_size;
}

Font::Glyph Font::findGlyph( char character ) const
{
    assert( character >= '0' );
    assert( character <= '9' );

    return std::move( m_glyphs.at( character - '0' ) );
}


} // namespace knack
