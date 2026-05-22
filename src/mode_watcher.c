#include "mode_watcher.h"

#include <raylib.h>

static Mode CURRENT_MODE = MODE_WELCOME;

// TODO: for normal mode check if file is open in order to perform mode switch
// TODO: think about system mode for open directories set projects, anchors etc
// this system mode should replace Welcome/Open
void MW_HandleModeChange()
{
    if (CURRENT_MODE == MODE_NORMAL) {
        if (IsKeyPressed(KEY_I) || IsKeyPressed(KEY_A)) {
            CURRENT_MODE = MODE_INSERT;
        }
        if (IsKeyPressed(KEY_R)) {
            CURRENT_MODE = MODE_REPLACE;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_SEMICOLON)) {
            CURRENT_MODE = MODE_COMMAND;
        }

        if (IsKeyPressed(KEY_V)) {
            CURRENT_MODE = MODE_VISUAL;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_V)) {
            CURRENT_MODE = MODE_VISUAL_LINE;
        }
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_V)) {
            CURRENT_MODE = MODE_VISUAL_BLOCK;
        }
    }

    if (CURRENT_MODE != MODE_NORMAL) {
        if (CURRENT_MODE == MODE_COMMAND_LINE && IsKeyPressed(KEY_ESCAPE)) {
            CURRENT_MODE = MODE_COMMAND;
        }

        if (CURRENT_MODE != MODE_COMMAND_LINE && CURRENT_MODE != MODE_WELCOME &&
            IsKeyPressed(KEY_ESCAPE))
        {
            CURRENT_MODE = MODE_NORMAL;
        }

        if (CURRENT_MODE == MODE_COMMAND && IsKeyDown(KEY_LEFT_SHIFT) &&
            IsKeyPressed(KEY_ONE))
        {
            CURRENT_MODE = MODE_COMMAND_LINE;
        }
    }

    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_O)) {
        CURRENT_MODE = MODE_OPEN;
    }
}

Mode MW_GetMode()
{
    return CURRENT_MODE;
}
