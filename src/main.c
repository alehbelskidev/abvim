#include <raylib.h>
#include <stddef.h>

#include "editor_config.h"
#include "info_line.h"
#include "layout.h"
#include "mode_badge.h"
#include "mode_watcher.h"

int main(void)
{
    EditorConfig* config = EC_Init();
    ModeWatcher* mw = MW_Init();

    const int DEFAULT_SCREEN_W = 800;
    const int DEFAULT_SCREEN_H = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(DEFAULT_SCREEN_W, DEFAULT_SCREEN_H, "ABVIM");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    LayoutContext* ctx = CTX_Init();
    EC_LoadFont(config);

    while (!WindowShouldClose()) {
        MW_HandleModeChange(mw);

        if (CTX_ShouldUpdate(ctx)) {
            CTX_Update(ctx);
        }

        BeginDrawing();
        ClearBackground(config->theme.neutral);

        BlockLayout infoLine = IL_Draw(config, ctx->layout);
        MB_Draw(config, infoLine, mw->mode);

        EndDrawing();
    }

    EC_UnloadFont(config);
    CloseWindow();

    EC_FREE(config);
    CTX_FREE(ctx);

    return 0;
}
