#include "window.hpp"
#include <assert.h>
#include <stdexcept>

namespace knack {

Window::Window( int width, int height ) :
    m_mouseX( 0.d ),
    m_mouseY( 0.d ),
    m_click( nullptr )
{
    m_window = glfwCreateWindow( width, height, "Knock", nullptr, nullptr );
    if ( m_window == nullptr ) {
        throw std::runtime_error( "Can't create GLFW window" );
    }

    glfwMakeContextCurrent( m_window );
    glfwSetWindowUserPointer( m_window, this );
    glfwSetCursorPosCallback( m_window, onMouseMove  );
    glfwSetMouseButtonCallback( m_window, onMouseClick );
    glfwSetWindowCloseCallback( m_window, onShouldClose );
}

Window::~Window()
{
    assert( m_window != nullptr );

    glfwDestroyWindow( m_window );
}

void Window::setClickHandler( Window::ClickHandler handler )
{
    m_click = handler;
}


void Window::readViewportSize( int & width, int & height )
{
    assert( m_window != nullptr );

    glfwGetFramebufferSize( m_window, & width, & height );
}

bool Window::shouldClose()
{
    assert( m_window != nullptr );

    glfwPollEvents();
    return glfwWindowShouldClose( m_window ) == GL_TRUE;
}

void Window::update()
{
    assert( m_window != nullptr );

    glfwSwapBuffers( m_window );
}


void Window::onMouseMove( GLFWwindow * window, double x, double y )
{
    assert( window != nullptr );

    Window * self = static_cast< Window * >( glfwGetWindowUserPointer( window ) );
    if ( self != nullptr ) {
        assert( self->m_window == window );

        self->m_mouseX = x;
        self->m_mouseY = y;
    }
}

void Window::onMouseClick( GLFWwindow * window, int button, int action, int mode )
{
    assert( window != nullptr );

    Window * self = static_cast< Window * >( glfwGetWindowUserPointer( window ) );
    if ( self != nullptr ) {
        assert( self->m_window == window );

        if ( button == GLFW_MOUSE_BUTTON_LEFT ) {
            if ( action == GLFW_PRESS ) {
                if ( self->m_click != nullptr ) {
                    self->m_click( self, self->m_mouseX, self->m_mouseY );
                }
            }
        }
    }
}

void Window::onShouldClose( GLFWwindow * window )
{
    assert( window != nullptr );

    glfwSetWindowShouldClose( window, GL_TRUE );
}


} // namespace knack
