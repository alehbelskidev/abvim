#include "mode_watcher.h"
#include "raylib.h"

int main(void)
{
    ModeWatcher* mw = MW_New();

    const int screenWidth = 800;
    const int screenHeight = 450;

    SetWindowState(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "ABVIM");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // FRAME
        ClearBackground(BLACK);
        MW_Draw(mw);
        // END FRAME

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
