#pragma once

#include <string>
#include <vector>

namespace knack {

class Render
{

public:
    Render();

    void begin( int width, int height );
    void end();

    void useColor( float r, float g, float b );
    void drawDisk( float x, float y, float r, int segments );
//    void drawText( float x, float y, const std::string & text );
};

} // namespace knack
