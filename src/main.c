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
    EC_LoadFont(config);
    float screenH = GetScreenHeight();

    MW_Calc(config, screenH);

    while (!WindowShouldClose()) {
        if (screenH != GetScreenHeight() || MW_ShouldReCalc()) {
            screenH = GetScreenHeight();
            MW_Calc(config, screenH);
        }

        BeginDrawing();
        // FRAME
        ClearBackground(config->theme.neutral);
        MW_Draw(config);
        // END FRAME
        EndDrawing();
    }

    EC_UnloadFont(config);
    CloseWindow();

    return 0;
}
