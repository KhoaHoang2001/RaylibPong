#include <raylib.h>

int ballX = 400;
int ballY = 300;
int ballVelocityX = 5;
int ballVelocityY = 0;
int paddle1X = 10;
int paddle1Y = 260;
int paddle2X = 780;
int paddle2Y = 260;
int score1 = 0;
int score2 = 0;

void DrawMainMenu()
{
    DrawText("PONG", 100, 200, 200, RAYWHITE);
    //DrawText("START GAME", 0, 0, 50, GRAY);
    //DrawText("QUIT", 0, 0, 50, GRAY);
}

void ResetGame()
{
    ballX = 395;
    ballY = 295;
}

void MoveBall()
{
    ballX += ballVelocityX;
    ballY += ballVelocityY;
}

void CheckInput()
{
    if(IsKeyDown(KEY_W))
    {
        if(paddle1Y != 0)
            paddle1Y -= 5;
    }
    else if(IsKeyDown(KEY_S))
    {
        if(paddle1Y != 520)
            paddle1Y += 5;
    }
    else if(IsKeyDown(KEY_UP))
    {
        if(paddle2Y != 0)
            paddle2Y -= 5;
    }
    else if(IsKeyDown(KEY_DOWN))
    {
        if(paddle2Y != 520)
            paddle2Y += 5;
    }
    else if(IsKeyDown(KEY_R))
    {
        ResetGame();
    }
}

void CheckBallCollision()
{

    if(ballY <= 0)
    {
        ballVelocityY += 5;
    }
    else if(ballY >= 580)
    {
        ballVelocityY -= 5;
    }
    else if(ballY > 0 && ballY < 580)
    {
        if(ballX == 20)
        {
            if(ballY >= paddle1Y - 20 && ballY < paddle1Y + 30)
            {
                ballVelocityX = 5;
                ballVelocityY = -5;
            }
            else if(ballY >= paddle1Y + 30 && ballY <= paddle1Y + 50)
            {
                ballVelocityX = 5;
                ballVelocityY = 0;
            }
            else if(ballY > paddle1Y + 50 && ballY <= paddle1Y + 80)
            {
                ballVelocityX = 5;
                ballVelocityY = 5;
            }
        }
        else if(ballX == 780)
        {
            if(ballY >= paddle2Y - 20 && ballY < paddle2Y + 30)
            {
                ballVelocityX = -5;
                ballVelocityY = -5;
            }
            else if(ballY >= paddle2Y + 30 && ballY <= paddle2Y + 50)
            {
                ballVelocityX = -5;
                ballVelocityY = 0;
            }
            else if(ballY > paddle2Y + 50 && ballY <= paddle2Y + 80)
            {
                ballVelocityX = -5;
                ballVelocityY = 5;
            }
        }
    }
}

void DrawGame()
{
    DrawLine(400, 0, 400, 600, RAYWHITE);
    DrawCircle(ballX, ballY, 10, RAYWHITE);
    DrawRectangle(paddle1X, paddle1Y, 10, 80, RAYWHITE);
    DrawRectangle(paddle2X, paddle2Y, 10, 80, RAYWHITE);
    DrawText(score1, )
}

int main () {

    InitWindow(800, 600, "PONG");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        //DrawMainMenu();
        CheckInput();
        MoveBall();
        CheckBallCollision();
        DrawGame();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}