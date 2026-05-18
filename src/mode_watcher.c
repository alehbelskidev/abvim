#include "mode_watcher.h"

#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "editor_config.h"
#include "layout.h"

ModeWatcher* mw;

// FYI: not covered by theme, find out how
static const ModeStyle MODE_STYLES[] = {
    [MODE_NORMAL] = {.bg = {97, 175, 239, 255}, .fg = {40, 44, 52, 255}, .label = "NORMAL"},
    [MODE_INSERT] = {.bg = {198, 120, 221, 255}, .fg = {40, 44, 52, 255}, .label = "INSERT"},
    [MODE_REPLACE] = {.bg = {224, 108, 117, 255}, .fg = {40, 44, 52, 255}, .label = "REPLACE"},
    [MODE_VISUAL] = {.bg = {229, 192, 123, 255}, .fg = {40, 44, 52, 255}, .label = "VISUAL"},
    [MODE_VISUAL_BLOCK] = {.bg = {209, 154, 102, 255}, .fg = {40, 44, 52, 255}, .label = "V-BLOCK"},
    [MODE_VISUAL_LINE] = {.bg = {235, 203, 139, 255}, .fg = {40, 44, 52, 255}, .label = "V-LINE"},
    [MODE_COMMAND] = {.bg = {152, 195, 121, 255}, .fg = {40, 44, 52, 255}, .label = "COMMAND"},
    [MODE_COMMAND_LINE] = {.bg = {86, 182, 194, 255}, .fg = {40, 44, 52, 255}, .label = "C-LINE"}};

void MW_Init(EditorConfig* c)
{
    mw = calloc(1, sizeof(ModeWatcher));
    if (mw != NULL) {
        mw->mode = MODE_NORMAL;
        mw->modeStyle = MODE_STYLES[mw->mode];
        mw->roundness = c->roundness;
        mw->segments = c->segments;
    }
}
void MW_FREE()
{
    if (mw != NULL) {
        free(mw);
    }
}

void MW_SetMode(Mode m)
{
    mw->mode = m;
    mw->modeStyle = MODE_STYLES[mw->mode];
    mw->isDirty = true;
}

void MW_Calc(const EditorConfig* c, LayoutContext* ctx)
{
    Vector2 fontSize = MeasureTextEx(c->font, mw->modeStyle.label, c->fontSize, 0);
    float paddingX = fontSize.x * 0.5f;
    float paddingY = paddingX / 2.0f;
    float blockH = fontSize.y + paddingY;
    float blockW = fontSize.x + paddingX;

    mw->layout = (BlockLayout){
        .padding = {paddingX, paddingY},
        .size = {blockW, blockH},
        .offset = {ctx->infoLIneOffset.x, ctx->infoLIneOffset.y},
    };
    mw->fontSize = fontSize;
    mw->isDirty = false;

    ctx->infoLineH = blockH;
}

bool MW_ShouldReCalc()
{
    return mw->isDirty;
}

void MW_Draw(const EditorConfig* c)
{
    ModeStyle* ms = &mw->modeStyle;
    BlockLayout* l = &mw->layout;

    Rectangle rect = {l->offset.x, l->offset.y, l->size.x, l->size.y};
    DrawRectangleRounded(rect, mw->roundness, mw->segments, ms->bg);

    Vector2 textPos = {l->offset.x + l->padding.x / 2,
                       l->offset.y + (l->size.y / 2) - (mw->fontSize.y / 2)};
    DrawTextEx(c->font, ms->label, textPos, c->fontSize, 0, ms->fg);
}
