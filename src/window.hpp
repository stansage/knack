#pragma once
#include <GLFW/glfw3.h>
#include <functional>

namespace knack {

class Window
{
public:
    using ClickHandler = std::function< void( Window *, double, double ) >;

    Window( int width, int height );
    ~Window();

    void setClickHandler( ClickHandler handler );

    void readViewportSize( int & width, int & height );
    bool shouldClose();
    void update();


private:
    static void onMouseMove( GLFWwindow * window, double x, double y );
    static void onMouseClick( GLFWwindow * window, int button, int action, int mode );
    static void onShouldClose( GLFWwindow * window );

private:
    Window( Window & );
    Window( Window && );
    Window & operator =( Window & );

private:
    GLFWwindow * m_window;
    double m_mouseX;
    double m_mouseY;
    ClickHandler m_click;
};

} // namespace knack
