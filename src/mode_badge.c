#include "mode_badge.h"

#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "editor_config.h"
#include "layout.h"
#include "mode_watcher.h"

ModeBadge* self;

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

void MB_Init(EditorConfig* c, ModeWatcher* mw)
{
    self = calloc(1, sizeof(ModeBadge));
    if (self != NULL) {
        self->mode = mw->mode;
        self->modeStyle = MODE_STYLES[self->mode];
        self->roundness = c->roundness;
        self->segments = c->segments;
    }
}
void MB_FREE()
{
    if (self != NULL) {
        free(self);
    }
}

void MB_SetMode(Mode m)
{
    if (self->mode != m) {
        self->mode = m;
        self->modeStyle = MODE_STYLES[m];
        self->isDirty = true;
    }
}

void MB_Calc(const EditorConfig* c, LayoutContext* ctx)
{
    Vector2 fontSize = MeasureTextEx(c->font, self->modeStyle.label, c->fontSize, 0);
    float paddingX = fontSize.x * 0.5f;
    float paddingY = paddingX / 2.0f;
    float blockH = ctx->infoLineH;
    float blockW = fontSize.x + paddingX;

    self->layout = (BlockLayout){
        .padding = {paddingX, paddingY},
        .size = {blockW, blockH},
        .offset = {ctx->infoLIneOffset.x, ctx->infoLIneOffset.y},
    };
    self->fontSize = fontSize;
    self->isDirty = false;
}

bool MB_ShouldReCalc()
{
    return self->isDirty;
}

void MB_Draw(const EditorConfig* c)
{
    ModeStyle* ms = &self->modeStyle;
    BlockLayout* l = &self->layout;

    Rectangle rect = {l->offset.x, l->offset.y, l->size.x, l->size.y};
    DrawRectangleRounded(rect, self->roundness, self->segments, ms->bg);

    Vector2 textPos = {l->offset.x + l->padding.x / 2,
                       l->offset.y + (l->size.y / 2) - (self->fontSize.y / 2)};
    DrawTextEx(c->font, ms->label, textPos, c->fontSize, 0, ms->fg);
}
