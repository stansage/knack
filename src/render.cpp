#include "render.hpp"
#include "font.hpp"
#include <GLFW/glfw3.h>
#include <cmath>

namespace knack {

Render::Render()
{
//    glShadeModel( GL_FLAT );
}

void Render::begin( int width, int height )
{
    glClear( GL_COLOR_BUFFER_BIT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glViewport( 0, 0, width, height );
}

void Render::end()
{
    glFlush();
}

void Render::useColor( float r, float g, float b )
{
    glColor3f( r, g, b );
}

void Render::drawDisk( float x, float y, float r, int segments )
{
    //! Апроксимируем окружность треугольниками
    glBegin( GL_TRIANGLE_FAN );
    glVertex2f( x, y );
    for( int n = 0; n <= segments; ++n ) {
        const auto t = 2.f * M_PI * n / segments;
        glVertex2f( x + std::sin( t ) * r, y + std::cos( t ) * r );
    }
    glEnd();
}

void Render::drawText( float x, float y, const Font & font, const std::string & text )
{
    //! Отрисовываем каждый символ строки глифом заданного шрифта
    for ( auto i = 0; i <  text.length(); ++ i ) {
        glBegin( GL_LINE_STRIP );
        for ( const auto & point : font.findGlyph( text[ i ] ) ) {
            glVertex2f( x + point.first + i * font.getSize(), y + point.second );
        }
        glEnd();
    }
}


} // namespace knack
