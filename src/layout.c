#include "layout.h"

#include <raylib.h>
#include <stdlib.h>

LayoutContext* CTX_Init()
{
    LayoutContext* ctx = malloc(sizeof(LayoutContext));

    if (ctx != NULL) {
        ctx->screenW = GetScreenWidth();
        ctx->screenH = GetScreenHeight();
    }

    return ctx;
}

void CTX_FREE(LayoutContext* ctx)
{
    if (ctx != NULL) {
        free(ctx);
    }
}

void CTX_Update(LayoutContext* ctx)
{
    ctx->screenH = GetScreenHeight();
    ctx->screenW = GetScreenWidth();
}

bool CTX_ShouldUpdate(LayoutContext* ctx)
{
    return ctx->screenW != GetScreenWidth() || ctx->screenH != GetScreenHeight();
}
