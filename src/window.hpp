#pragma once
#include <GLFW/glfw3.h>
#include <functional>

namespace knack {

//! Класс окна
class Window
{
public:
    using ClickHandler = std::function< void( Window *, double, double ) >;

    //! Создает окно с указанной шириной и высотой
    Window( int width, int height );
    //! Разрушает окно
    virtual ~Window();

    //! Устанавливает обработчик нажатия левой кнопки мыши
    void setClickHandler( ClickHandler handler );

    //! Считывает ширину и высоту области рисования
    void readViewportSize( int & width, int & height );

    //! Проверяет момент закрытия окна
    bool shouldClose();

    //! Обновляет содержимое окна
    void update();

private:
    //! Обработчик движения мыши
    static void onMouseMove( GLFWwindow * window, double x, double y );
    //! Обработчик клика мыши
    static void onMouseClick( GLFWwindow * window, int button, int action, int mode );
    //! Обработчик закрытия окна
    static void onShouldClose( GLFWwindow * window );

private:
    //! Запрет копирования
    Window( Window & );
    Window( Window && );
    Window & operator =( Window & );

private:
    GLFWwindow * m_window;
    double m_mouseX = 0;
    double m_mouseY = 0;
    ClickHandler m_click;
};

} // namespace knack
