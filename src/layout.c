#include "layout.h"

#include <raylib.h>
#include <stdlib.h>

LayoutContext* CTX_Init()
{
    LayoutContext* ctx = calloc(1, sizeof(LayoutContext));

    if (ctx != NULL) {
        ctx->layout.size.x = GetScreenWidth();
        ctx->layout.size.y = GetScreenHeight();
        ctx->layout.padding = (Vector2){16, 16};
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
    ctx->layout.size.x = GetScreenHeight();
    ctx->layout.size.y = GetScreenWidth();
}

bool CTX_ShouldUpdate(LayoutContext* ctx)
{
    return ctx->layout.size.x != GetScreenWidth() || ctx->layout.size.y != GetScreenHeight();
}
