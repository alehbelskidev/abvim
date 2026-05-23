#include <raylib.h>
#include <stddef.h>

#include "ctx.h"
#include "editor_config.h"
#include "info_line.h"
#include "layout.h"
#include "mode_badge.h"
#include "mode_watcher.h"
#include "welcome.h"

int main(void)
{
    EditorConfig* config = EC_Init();
    Context* ctx = CTX_Init();

    const int DEFAULT_SCREEN_W = 800;
    const int DEFAULT_SCREEN_H = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(DEFAULT_SCREEN_W, DEFAULT_SCREEN_H, "ABVIM");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    EC_LoadFont(config);

    ctx->root =
        (BlockLayout){{16, 16}, {0, 0}, {GetScreenWidth(), GetScreenHeight()}};

    WS_Init();

    while (!WindowShouldClose()) {
        ctx->root.size = (Vector2){GetScreenWidth(), GetScreenHeight()};
        ctx->mousePos = GetMousePosition();
        ctx->mouseDelta = GetMouseDelta();
        MW_HandleModeChange();

        BeginDrawing();
        ClearBackground(config->theme.neutral);

        if (MW_GetMode() == MODE_WELCOME) {
            WS_Draw(config, ctx, ctx->root);
        }

        BlockLayout infoLine = IL_Draw(config, ctx->root);
        MB_Draw(config, infoLine, MW_GetMode());

        EndDrawing();
    }

    EC_UnloadFont(config);
    CloseWindow();

    EC_FREE(config);
    CTX_FREE(ctx);
    WS_FREE();

    return 0;
}
