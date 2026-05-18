#include <raylib.h>

#include "editor_config.h"
#include "info_line.h"
#include "layout.h"
#include "mode_watcher.h"

int main(void)
{
    EditorConfig* config = EC_Init();
    MW_Init(config);
    IL_Init(config);

    const int DEFAULT_SCREEN_W = 800;
    const int DEFAULT_SCREEN_H = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(DEFAULT_SCREEN_W, DEFAULT_SCREEN_H, "ABVIM");
    SetTargetFPS(60);

    LayoutContext* ctx = CTX_Init();
    EC_LoadFont(config);

    IL_Calc(config, ctx);
    MW_Calc(config, ctx);

    while (!WindowShouldClose()) {
        if (CTX_ShouldUpdate(ctx)) {
            CTX_Update(ctx);
            IL_Calc(config, ctx);
            MW_Calc(config, ctx);
        }
        if (MW_ShouldReCalc()) {
            MW_Calc(config, ctx);
        }

        BeginDrawing();
        // FRAME
        ClearBackground(config->theme.neutral);
        IL_Draw(config);
        MW_Draw(config);
        // END FRAME
        EndDrawing();
    }

    EC_UnloadFont(config);
    CloseWindow();

    EC_FREE(config);
    MW_FREE();
    CTX_FREE(ctx);

    return 0;
}
