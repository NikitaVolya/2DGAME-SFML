#pragma once

#ifndef SETUP_H
#define SETUP_H

#define CREATOR_MODE true
#define TILES_FILES "resources\\sprites\\tile\\"

#define SCALE 3

#define FRAME_RATE 60
#define FRAME_RATE_F 60.f

#define PIXEL_SIZE (16 * SCALE)
#define PIXEL_SIZE_F (16.f * SCALE)

#define WIDTH 16
#define HEIGHT 9

#define SCREEN_WIDTH (WIDTH * PIXEL_SIZE)
#define SCREEN_HEIGHT (HEIGHT * PIXEL_SIZE)
#define SCREEN_SIZE sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)

#define SPEED_SCREEN_TO_ENTITY 0.015f
#define MINIMUM_SCREEN_STEP PIXEL_SIZE

#define Pi 3.1415;
#define F 0.28f

#endif // !SETUP_H


