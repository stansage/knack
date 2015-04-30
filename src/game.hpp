#pragma once

#include <memory>

namespace knack {

class Target;
class Window;

//! Класс игры
class Game
{
public:
    //! Структура конфигурации
    struct Config
    {
        int diskQuality = 0;
        float fontSize = 0;
        float speedMax = 0;
        float radiusMin = 0;
        float radiusMax = 0;
        int rewardMax = 0;
        int windowWidth = 0;
        int windowHeight = 0;
    };

    //! Создает игру с указанной конфигурацией
    Game( const Config & config );
    //! Разрушает игру
    virtual ~Game();

    //! Запускает игру
    int run();

private:
    //! Сбрасывает цель в начальное состояние
    void resetTarget();
    //! Обработчик клика мыши
    void onWindowClick( Window * window, double x, double y );
    //! Обработчик ошибок
    static void onError( int error, const char * message );

private:
    //! Запрет копирования
    Game( Game & );
    Game( Game && );
    Game & operator =( Game & );

private:
    bool m_glfw;
    Config m_config;
    int m_score = 0;
    std::shared_ptr<Target> m_target;
};

} // namespace knack
