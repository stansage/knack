#include "game.hpp"
#include <iostream>

int main( int, char * [] )
{
    knack::Game::Config config;
    config.windowWidth = 1024;
    config.windowHeight = 768;
    config.diskQuality = 30;
    config.radiusMin = 0.1;
    config.radiusMax = 0.2;
    config.speedMax = 0.001;
    config.rewardMax = 100;

    knack::Game game( config );

    return game.run();
}
