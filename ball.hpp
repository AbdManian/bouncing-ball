#ifndef BALL_HPP_
#define BALL_HPP_

#include "raylib.h"

struct Ball
{
	int x;
	int y;
	float radius;
	int speed_x;
	int speed_y;
	Color color;
};


// Move position of the ball based on speed of the ball
void move_ball(Ball& ball);

// Bounce ball on the boundaries of a given screen size
void bounce_ball(Ball& ball, int width, int height);

// Draw ball
void draw_ball(Ball ball);

#endif /* BALL_HPP_ */
