#include "mode_watcher.h"

#include <raylib.h>
#include <stdlib.h>

#include "editor_config.h"

ModeWatcher* mw;

static const ModeStyle MODE_STYLES[] = {
    [MODE_NORMAL] = {.bg = {97, 175, 239, 255}, .fg = {40, 44, 52, 255}, .label = "NORMAL"},
    [MODE_INSERT] = {.bg = {198, 120, 221, 255}, .fg = {40, 44, 52, 255}, .label = "INSERT"},
    [MODE_REPLACE] = {.bg = {224, 108, 117, 255}, .fg = {40, 44, 52, 255}, .label = "REPLACE"},
    [MODE_VISUAL] = {.bg = {229, 192, 123, 255}, .fg = {40, 44, 52, 255}, .label = "VISUAL"},
    [MODE_VISUAL_BLOCK] = {.bg = {209, 154, 102, 255}, .fg = {40, 44, 52, 255}, .label = "V-BLOCK"},
    [MODE_VISUAL_LINE] = {.bg = {235, 203, 139, 255}, .fg = {40, 44, 52, 255}, .label = "V-LINE"},
    [MODE_COMMAND] = {.bg = {152, 195, 121, 255}, .fg = {40, 44, 52, 255}, .label = "COMMAND"},
    [MODE_COMMAND_LINE] = {.bg = {86, 182, 194, 255}, .fg = {40, 44, 52, 255}, .label = "C-LINE"}};

void MW_Init()
{
    mw = malloc(sizeof(ModeWatcher));
    if (mw != NULL) {
        mw->mode = MODE_NORMAL;
        mw->modeStyle = MODE_STYLES[mw->mode];
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
}

void MW_Draw(const EditorConfig* ec)
{
    ModeStyle* ms = &mw->modeStyle;
    int screenH = GetScreenHeight();

    Vector2 textSize = MeasureTextEx(ec->font, ms->label, ec->fontSize, 0);
    float paddingX = textSize.x * 0.5f;
    float paddingY = paddingX / 2.0f;
    float blockH = textSize.y + paddingY;
    float blockW = textSize.x + paddingX;
    float blockY = screenH - blockH;

    DrawRectangle(0, blockY, blockW, blockH, ms->bg);
    DrawTextEx(ec->font, ms->label,
               (Vector2){paddingX / 2, blockY + (blockH / 2) - (textSize.y / 2)}, ec->fontSize, 0,
               ms->fg);
}
