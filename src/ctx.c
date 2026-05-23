#include "ctx.h"

#include <raylib.h>
#include <stdlib.h>

#include "layout.h"

Context* CTX_Init()
{
    Context* ctx = calloc(1, sizeof(Context));
    if (ctx != NULL) {
        ctx->root = (BlockLayout){
            {16, 16},
            {0, 0},
            {GetScreenWidth(), GetScreenHeight()},
        };
    }

    return ctx;
}

void CTX_FREE(Context* ctx)
{
    if (ctx != NULL) {
        free(ctx);
    }
}
