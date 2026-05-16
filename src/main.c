#include "editor_config.h"
#include "mode_watcher.h"
#include "raylib.h"

int main(void)
{
    EditorConfig* config = EC_Init();
    MW_Init();

    const int screenWidth = 800;
    const int screenHeight = 450;

    SetWindowState(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "ABVIM");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // FRAME
        ClearBackground(BLACK);
        MW_Draw(config);
        // END FRAME

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
