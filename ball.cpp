#include "ball.hpp"


void move_ball(Ball& ball)
{
	ball.x = ball.x + ball.speed_x;
	ball.y = ball.y + ball.speed_y;
}

void bounce_ball(Ball& ball, int width, int height)
{
	if (ball.y>(height-ball.radius))
	{
		ball.y = height - ball.radius;
		ball.speed_y = ball.speed_y * -1 ;
	}

	if (ball.x>(width-ball.radius))
	{
		ball.x = width - ball.radius;
		ball.speed_x = ball.speed_x * -1;
	}

	if (ball.y<ball.radius)
	{
		ball.y = ball.radius;
		ball.speed_y = ball.speed_y * -1;
	}

	if (ball.x<ball.radius)
	{
		ball.x = ball.radius;
		ball.speed_x = ball.speed_x * -1;
	}

}

void draw_ball(Ball ball)
{
    DrawCircle(ball.x, ball.y, ball.radius, ball.color);
}

