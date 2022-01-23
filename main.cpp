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


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;
    const int start_x = screen_width / 3;
    const int start_y = screen_height / 3;

    Ball ball_r {start_x, start_y, 10.0f, -4, -4, RED };
    Ball ball_b {start_x, start_y, 15.0f, -4,  4, BLUE};

    InitWindow(screen_width, screen_height, "Bouncing Ball!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	ball_r.x = ball_r.x + ball_r.speed_x;
    	ball_r.y = ball_r.y + ball_r.speed_y;

    	if (ball_r.y>(screen_height-ball_r.radius))
    	{
    		ball_r.y = screen_height - ball_r.radius;
    		ball_r.speed_y = ball_r.speed_y * -1 ;
    	}

    	if (ball_r.x>(screen_width-ball_r.radius))
    	{
    		ball_r.x = screen_width - ball_r.radius;
    		ball_r.speed_x = ball_r.speed_x * -1;
    	}

    	if (ball_r.y<ball_r.radius)
    	{
    		ball_r.y = ball_r.radius;
    		ball_r.speed_y = ball_r.speed_y * -1;
    	}

    	if (ball_r.x<ball_r.radius)
    	{
    		ball_r.x = ball_r.radius;
    		ball_r.speed_x = ball_r.speed_x * -1;
    	}


    	ball_b.x = ball_b.x + ball_b.speed_x;
    	ball_b.y = ball_b.y + ball_b.speed_y;

    	if (ball_b.y>(screen_height-ball_b.radius))
    	{
    		ball_b.y = screen_height - ball_b.radius;
    		ball_b.speed_y = ball_b.speed_y * -1 ;
    	}

    	if (ball_b.x>(screen_width-ball_b.radius))
    	{
    		ball_b.x = screen_width - ball_b.radius;
    		ball_b.speed_x = ball_b.speed_x * -1;
    	}

    	if (ball_b.y<ball_b.radius)
    	{
    		ball_b.y = ball_b.radius;
    		ball_b.speed_y = ball_b.speed_y * -1;
    	}

    	if (ball_b.x<ball_b.radius)
    	{
    		ball_b.x = ball_b.radius;
    		ball_b.speed_x = ball_b.speed_x * -1;
    	}

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircle(ball_r.x, ball_r.y, ball_r.radius, ball_r.color);
            DrawCircle(ball_b.x, ball_b.y, ball_b.radius, ball_b.color);

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
