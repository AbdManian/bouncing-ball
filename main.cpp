/**
 * Bouncing Ball!
 *
 */
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    int ball_x = screen_width / 3;
    int ball_y = screen_height / 3;
    float ball_radius = 10;
    int ball_speed_x = 4;
    int ball_speed_y = 4;

    InitWindow(screen_width, screen_height, "Bouncing Ball!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	ball_x = ball_x + ball_speed_x;
    	ball_y = ball_y + ball_speed_y;

    	if (ball_y>(screen_height-ball_radius))
    	{
    		ball_y = screen_height - ball_radius;
    		ball_speed_y = ball_speed_y * -1 ;
    	}

    	if (ball_x>(screen_width-ball_radius))
    	{
    		ball_x = screen_width - ball_radius;
    		ball_speed_x = ball_speed_x * -1;
    	}

    	if (ball_y<ball_radius)
    	{
    		ball_y = ball_radius;
    		ball_speed_y = ball_speed_y * -1;
    	}

    	if (ball_x<ball_radius)
    	{
    		ball_x = ball_radius;
    		ball_speed_x = ball_speed_x * -1;
    	}

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

//            DrawRectangle(0, 0, screen_width, screen_height, BLACK);
//            DrawRectangle(10, 10, screen_width-20, screen_height-20, RAYWHITE);

            DrawCircle(ball_x, ball_y, ball_radius, MAROON);

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
