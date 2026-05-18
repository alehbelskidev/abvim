#include "info_line.h"

#include <raylib.h>
#include <stdlib.h>

InfoLine* il;

void IL_Init(EditorConfig* c)
{
    il = calloc(1, sizeof(InfoLine));
    if (il != NULL) {
        il->layout.padding.x = 20;
        il->layout.padding.y = 20;
        il->lineThick = c->lineThick;
        il->roundness = c->roundness;
        il->segments = c->lineThick;
    }
}

void IL_FREE(InfoLine* il)
{
    if (il != NULL) {
        free(il);
    }
}

void IL_Calc(EditorConfig* c, LayoutContext* ctx)
{
    BlockLayout* l = &il->layout;

    l->size.y = ctx->infoLineH;
    l->size.x = ctx->screenW - l->padding.x * 2;
    l->offset.x = l->padding.x;
    l->offset.y = ctx->screenH - l->padding.y - l->size.y;

    ctx->infoLIneOffset = l->offset;
}

void IL_Draw(EditorConfig* c)
{
    BlockLayout* l = &il->layout;

    DrawRectangleRounded((Rectangle){l->offset.x, l->offset.y, l->size.x, l->size.y},
                         il->roundness - 0.1, il->segments, c->theme.secondary);
    DrawRectangleRoundedLinesEx((Rectangle){l->offset.x, l->offset.y, l->size.x, l->size.y},
                                il->roundness, il->segments, il->lineThick, c->theme.tertiary);
}
