#include "mode_watcher.h"

#include <raylib.h>
#include <stdlib.h>

ModeWatcher* MW_Init()
{
    ModeWatcher* mw = malloc(sizeof(ModeWatcher));
    if (mw != NULL) {
        mw->mode = MODE_WELCOME;
    }

    return mw;
}

void MW_FREE(ModeWatcher* mw)
{
    if (mw != NULL) {
        free(mw);
    }
}

// TODO: for normal mode check if file is open in order to perform mode switch
// TODO: think about system mode for open directories set projects, anchors etc
// this system mode should replace Welcome/Open
void MW_HandleModeChange(ModeWatcher* mw)
{
    if (mw->mode == MODE_NORMAL) {
        if (IsKeyPressed(KEY_I) || IsKeyPressed(KEY_A)) {
            mw->mode = MODE_INSERT;
        }
        if (IsKeyPressed(KEY_R)) {
            mw->mode = MODE_REPLACE;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_SEMICOLON)) {
            mw->mode = MODE_COMMAND;
        }

        if (IsKeyPressed(KEY_V)) {
            mw->mode = MODE_VISUAL;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_V)) {
            mw->mode = MODE_VISUAL_LINE;
        }
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_V)) {
            mw->mode = MODE_VISUAL_BLOCK;
        }
    }

    if (mw->mode != MODE_NORMAL) {
        if (mw->mode == MODE_COMMAND_LINE && IsKeyPressed(KEY_ESCAPE)) {
            mw->mode = MODE_COMMAND;
        }

        if (mw->mode != MODE_COMMAND_LINE && IsKeyPressed(KEY_ESCAPE)) {
            mw->mode = MODE_NORMAL;
        }

        if (mw->mode == MODE_COMMAND && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_ONE)) {
            mw->mode = MODE_COMMAND_LINE;
        }
    }

    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_O)) {
        mw->mode = MODE_OPEN;
    }
}
