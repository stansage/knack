#include "game.hpp"
#include "render.hpp"
#include "target.hpp"
#include "timer.hpp"
#include "window.hpp"
#include <assert.h>
#include <iostream>
#include <utility>

namespace knack {

Game::Game( const Config & config ) :
    m_config( config ),
    m_score( 0 )
{
    assert( config.diskQuality > 0 );
    assert( config.radiusMin > 0.0 );
    assert( config.radiusMin < 0.5 );
    assert( config.radiusMax > 0.0 );
    assert( config.radiusMax < 0.5 );
    assert( config.radiusMin < config.radiusMax );
    assert( config.rewardMax > 0 );
    assert( config.speedMax > 0.0 );
    assert( config.windowWidth > 0 );
    assert( config.windowHeight > 0 );

    m_glfw = glfwInit() == GL_TRUE;
}

Game::~Game()
{
    if ( m_glfw == true ) {
        glfwTerminate();
    }
}

int Game::run()
{
    using namespace std::placeholders;

    if ( m_glfw == false ) {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return 1;
    }

    glfwSetErrorCallback( onError );

    try {
        Timer timer;
        Render render;
        Window window( m_config.windowWidth, m_config.windowHeight );
        window.setClickHandler( std::bind( & Game::onWindowClick, this, _1, _2, _3 ) );

        resetTarget();

        while ( window.shouldClose() == false ) {
            if ( m_target->move() == false ) {
                resetTarget();
            }

            auto size = std::make_pair( 0, 0 );
            window.readViewportSize( size.first, size.second );

//            const auto score = std::to_string( m_score );
//            const auto fps = std::to_string( 1000000 / timer.getDuration() );

            render.begin( size.first, size.second );
            render.useColor( m_target->getColor().red, m_target->getColor().green, m_target->getColor().blue );
            render.drawDisk( m_target->getX(), m_target->getY(), m_target->getRadius(), m_config.diskQuality );
            render.useColor( 1.0, 1.0, 1.0 );
//            render.drawText( 0.1, 0.9, score );
//            render.drawText( 1.0 - fps.length() * Render::SYMBOL_WIDTH, 0.9f, fps );
            render.end();

            window.update();
            timer.reset();
        }

    } catch ( std::exception & exception ) {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    return 0;
}


void Game::resetTarget()
{
    m_target.reset( new Target( m_config.radiusMin, m_config.radiusMax, m_config.speedMax, m_config.rewardMax ) );
}

void Game::onWindowClick( Window * window, double x, double y )
{
    assert( window != nullptr );

    auto size = std::make_pair( 0, 0 );
    window->readViewportSize( size.first, size.second );

    x = 2.d * x / size.first - 1.f;
    y = 1.f - 2.d * y / size.second;

    if ( m_target->inArea( x, y ) == true ) {
        m_score += m_target->getReward();
        resetTarget();
    }

}

void Game::onError( int error, const char * message )
{
    std::cerr << error << ": " << message << std::endl;
}

} // namespace knack
