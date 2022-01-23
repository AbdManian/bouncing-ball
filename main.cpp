/**
 * Bouncing Ball!
 */
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

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;
    const int start_x = screen_width / 3;
    const int start_y = screen_height / 3;

    Ball ball_r {start_x, start_y,  8.0f, -4, -4, RED  };
    Ball ball_b {start_x, start_y, 12.0f, -4,  4, BLUE };
    Ball ball_g {start_x, start_y, 16.0f,  4,  4, GREEN};

    InitWindow(screen_width, screen_height, "Bouncing Ball!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
    	move_ball(ball_r);
    	move_ball(ball_b);
    	move_ball(ball_g);

    	bounce_ball(ball_r, screen_width, screen_height);
    	bounce_ball(ball_b, screen_width, screen_height);
    	bounce_ball(ball_g, screen_width, screen_height);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_ball(ball_r);
            draw_ball(ball_b);
            draw_ball(ball_g);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
