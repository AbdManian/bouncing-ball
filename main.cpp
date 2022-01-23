/**
 * Bouncing Ball!
 */
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    int ball_r_x = screen_width / 3;
    int ball_r_y = screen_height / 3;
    float ball_r_radius = 10;
    int ball_r_speed_x = -4;
    int ball_r_speed_y = -4;

    int ball_b_x = screen_width / 3;
    int ball_b_y = screen_height / 3;
    float ball_b_radius = 14;
    int ball_b_speed_x = 4;
    int ball_b_speed_y = -4;

    InitWindow(screen_width, screen_height, "Bouncing Ball!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	ball_r_x = ball_r_x + ball_r_speed_x;
    	ball_r_y = ball_r_y + ball_r_speed_y;

    	if (ball_r_y>(screen_height-ball_r_radius))
    	{
    		ball_r_y = screen_height - ball_r_radius;
    		ball_r_speed_y = ball_r_speed_y * -1 ;
    	}

    	if (ball_r_x>(screen_width-ball_r_radius))
    	{
    		ball_r_x = screen_width - ball_r_radius;
    		ball_r_speed_x = ball_r_speed_x * -1;
    	}

    	if (ball_r_y<ball_r_radius)
    	{
    		ball_r_y = ball_r_radius;
    		ball_r_speed_y = ball_r_speed_y * -1;
    	}

    	if (ball_r_x<ball_r_radius)
    	{
    		ball_r_x = ball_r_radius;
    		ball_r_speed_x = ball_r_speed_x * -1;
    	}


    	ball_b_x = ball_b_x + ball_b_speed_x;
    	ball_b_y = ball_b_y + ball_b_speed_y;

    	if (ball_b_y>(screen_height-ball_b_radius))
    	{
    		ball_b_y = screen_height - ball_b_radius;
    		ball_b_speed_y = ball_b_speed_y * -1 ;
    	}

    	if (ball_b_x>(screen_width-ball_b_radius))
    	{
    		ball_b_x = screen_width - ball_b_radius;
    		ball_b_speed_x = ball_b_speed_x * -1;
    	}

    	if (ball_b_y<ball_b_radius)
    	{
    		ball_b_y = ball_b_radius;
    		ball_b_speed_y = ball_b_speed_y * -1;
    	}

    	if (ball_b_x<ball_b_radius)
    	{
    		ball_b_x = ball_b_radius;
    		ball_b_speed_x = ball_b_speed_x * -1;
    	}

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircle(ball_r_x, ball_r_y, ball_r_radius, RED);
            DrawCircle(ball_b_x, ball_b_y, ball_b_radius, BLUE);

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
