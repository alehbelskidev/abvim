#include <raylib.h>

#include "editor_config.h"
#include "info_line.h"
#include "layout.h"
#include "mode_badge.h"

int main(void)
{
    EditorConfig* config = EC_Init();
    MB_Init(config);
    IL_Init(config);

    const int DEFAULT_SCREEN_W = 800;
    const int DEFAULT_SCREEN_H = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(DEFAULT_SCREEN_W, DEFAULT_SCREEN_H, "ABVIM");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    LayoutContext* ctx = CTX_Init();
    EC_LoadFont(config);

    IL_Calc(config, ctx);
    MB_Calc(config, ctx);

    while (!WindowShouldClose()) {
        MB_KeyEvent();

        if (CTX_ShouldUpdate(ctx)) {
            CTX_Update(ctx);
            IL_Calc(config, ctx);
            MB_Calc(config, ctx);
        }
        if (MB_ShouldReCalc()) {
            MB_Calc(config, ctx);
        }

        BeginDrawing();
        // FRAME
        ClearBackground(config->theme.neutral);
        IL_Draw(config);
        MB_Draw(config);
        // END FRAME
        EndDrawing();
    }

    EC_UnloadFont(config);
    CloseWindow();

    EC_FREE(config);
    MB_FREE();
    CTX_FREE(ctx);

    return 0;
}
