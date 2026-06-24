#include <raylib.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float LEFT_WALL_X = 90.0f;
const float RIGHT_WALL_X = 650.0f;
const float INITIAL_CAR_X = 300.0f;
const float INITIAL_CAR_Y = 450.0f;
const float INITIAL_ROAD_SPEED = 2.0f;
const float CAR_SIZE = 64.0f;
const float CAR_MOVE_SPEED = 2.0f;
const int GAME_OVER_FONT_SIZE = 65;
const int TARGET_FPS = 60;

void DrawGameOver(float x, float y, int fontSize) {
    DrawText("Game Over", x, y, fontSize, RED);
}

void ResetGame(Vector2 &carPosition, float &roadSpeed) {
    carPosition = {INITIAL_CAR_X, INITIAL_CAR_Y};
    roadSpeed = 0.0f;
}

int main() {
    SetAudioStreamBufferSizeDefault(1024);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cargame");
    InitAudioDevice();
    SetTargetFPS(TARGET_FPS);

    Texture2D carTexture = LoadTexture("assets/car.png");
    Texture2D roadTexture = LoadTexture("assets/road.png");
    Sound  crashsfx = LoadSound("assets/crash.wav");
    Music carsfx = LoadMusicStream("assets/car.wav");
    SetSoundVolume(crashsfx, 0.3f);
    SetTextureWrap(roadTexture, TEXTURE_WRAP_REPEAT);

    Vector2 carPosition = {INITIAL_CAR_X, INITIAL_CAR_Y};
    float roadSpeed = INITIAL_ROAD_SPEED;
    bool isGameOver = false;
    bool controlsSeized = false;
    bool hascrashsfxplayed = false;
    carsfx.looping = true;

    Rectangle roadSource = {0.0f, 0.0f, 64.0f, 64.0f};
    Rectangle roadDest = {0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT};
    Rectangle leftRoadWall = {0.0f, 0.0f, LEFT_WALL_X, SCREEN_HEIGHT};
    Rectangle rightRoadWall = {RIGHT_WALL_X, 0.0f, SCREEN_WIDTH - RIGHT_WALL_X, SCREEN_HEIGHT};

    int textWidth = MeasureText("Game Over", GAME_OVER_FONT_SIZE);
    float gameOverX = (SCREEN_WIDTH / 2) - (textWidth / 2);
    float gameOverY = (SCREEN_HEIGHT / 2) - (GAME_OVER_FONT_SIZE / 2);

    PlayMusicStream(carsfx);

    while (!WindowShouldClose()) {
        roadSource.y -= roadSpeed;
        UpdateMusicStream(carsfx);

        if (IsKeyDown(KEY_W)) {
            roadSpeed = INITIAL_ROAD_SPEED;
            ResumeMusicStream(carsfx);
        } else {
            roadSpeed = 0.0f;
            PauseMusicStream(carsfx);
        }

        if (!controlsSeized) {
            if (IsKeyDown(KEY_D)) carPosition.x += CAR_MOVE_SPEED;
            if (IsKeyDown(KEY_A)) carPosition.x -= CAR_MOVE_SPEED;
        }

        if (IsKeyPressed(KEY_R) && isGameOver) {
            isGameOver = false;
            controlsSeized = false;
            ResetGame(carPosition, roadSpeed);
            hascrashsfxplayed = false;
            ResumeMusicStream(carsfx);
        }

        Rectangle playerBox = {carPosition.x, carPosition.y, CAR_SIZE, CAR_SIZE};
        if (CheckCollisionRecs(playerBox, leftRoadWall) || CheckCollisionRecs(playerBox, rightRoadWall)) {
            isGameOver = true;
            controlsSeized = true;
            PauseMusicStream(carsfx);
            if (!hascrashsfxplayed) {
                PlaySound(crashsfx);
                hascrashsfxplayed = true;
            }
        }

        ClearBackground(WHITE);
        DrawTexturePro(roadTexture, roadSource, roadDest, Vector2{0, 0}, 0.0f, WHITE);
        DrawTextureEx(carTexture, carPosition, 0.0f, 4.0f, WHITE);
        if(IsKeyPressed(KEY_H)){
            DrawRectangleRec(leftRoadWall, Fade(RED, 0.3f));
            DrawRectangleRec(rightRoadWall, Fade(RED, 0.3f));
        }

        if (isGameOver) {
            DrawRectangle(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.5f));
            DrawGameOver(gameOverX, gameOverY, GAME_OVER_FONT_SIZE);
            roadSpeed = 0.0f;
        }

        EndDrawing();
    }

    UnloadTexture(carTexture);
    UnloadTexture(roadTexture);
    CloseWindow();
    return 0;
}
