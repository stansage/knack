#include "render.hpp"
#include <GL/gl.h>
#include <cmath>
#include <iostream>

namespace knack {

Render::Render()
{
    glShadeModel( GL_FLAT );
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
    glBegin( GL_TRIANGLE_FAN );
    glVertex2f( x, y );
    for( int n = 0; n <= segments; ++n ) {
        const auto t = 2.f * M_PI * n / segments;
        glVertex2f( x + std::sin( t ) * r, y + std::cos( t ) * r );
    }
    glEnd();
}


} // namespace knack
