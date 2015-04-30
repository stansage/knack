#pragma once

#include <memory>

namespace knack {

class Target;
class Window;

class Game
{
public:
    struct Config
    {
        int diskQuality = 0;
        float speedMax = 0;
        float radiusMin = 0;
        float radiusMax = 0;
        int rewardMax = 0;
        int windowWidth = 0;
        int windowHeight = 0;
    };

    Game( const Config & config );
    virtual ~Game();

    int run();

private:
    void resetTarget();
    void onWindowClick( Window * window, double x, double y );
    static void onError( int error, const char * message );

private:
    Game( Game & );
    Game( Game && );
    Game & operator =( Game & );

private:
    bool m_glfw;
    Config m_config;
    int m_score;
    std::shared_ptr<Target> m_target;
};

} // namespace knack
