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
    int screenHeight = GetScreenHeight();

    // TODO: following should be dynamic somehow;
    int blockHeight = 40;
    int fontSize = 20;
    if (ec != NULL) {
        fontSize = ec->fontSize;
    }
    int textPadding = 20;
    // END TODO

    int textWidth = MeasureText(ms->label, fontSize);
    DrawRectangle(0, screenHeight - blockHeight, textWidth + textPadding, blockHeight, ms->bg);
    DrawText(ms->label, textPadding / 2, screenHeight - blockHeight + (blockHeight - fontSize) / 2,
             fontSize, ms->fg);
}
