#pragma once

#include <SFML/System/Vector2.hpp>

#define CREATOR_MODE true
#define TILES_FILES "resources\\sprites\\tile\\"

#define FRAME_RATE 60

#define PIXEL_SIZE (16 * 3)

#define WIDTH 16
#define HEIGHT 9

#define SCREEN_WIDTH (WIDTH * PIXEL_SIZE)
#define SCREEN_HEIGHT (HEIGHT * PIXEL_SIZE)
#define SCREEN_SIZE sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)

#define SPEED_SCREEN_TO_ENTITY 0.015f
#define MINIMUM_SCREEN_STEP PIXEL_SIZE

#define F 0.28f