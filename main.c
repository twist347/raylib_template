#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define SCREEN_TITLE "raylib template"
#define TARGET_FPS 60
#define BG_COLOR WHITE

#define RECT_WIDTH 600.f
#define RECT_HEIGHT 300.f
#define RECT_COLOR RED

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    if (!IsWindowReady()) {
        TraceLog(LOG_ERROR, "Failed to create window");
        return EXIT_FAILURE;
    }

    SetTargetFPS(TARGET_FPS);

    const Rectangle rect = {
        .x = SCREEN_WIDTH * 0.5f - RECT_WIDTH * 0.5f, .y = SCREEN_HEIGHT * 0.5f - RECT_HEIGHT * 0.5f,
        .width = RECT_WIDTH, .height = RECT_HEIGHT
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BG_COLOR);

        DrawRectangleRec(rect, RECT_COLOR);

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}