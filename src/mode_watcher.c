#include "mode_watcher.h"

#include <raylib.h>
#include <stdlib.h>

ModeWatcher* MW_Init()
{
    ModeWatcher* self = malloc(sizeof(ModeWatcher));
    if (self != NULL) {
        self->mode = MODE_NORMAL;
    }

    return self;
}

void MW_FREE(ModeWatcher* self)
{
    if (self != NULL) {
        free(self);
    }
}

void MW_HandleModeChange(ModeWatcher* self)
{
    if (self->mode == MODE_NORMAL) {
        if (IsKeyPressed(KEY_I) || IsKeyPressed(KEY_A)) {
            self->mode = MODE_INSERT;
        }
        if (IsKeyPressed(KEY_R)) {
            self->mode = MODE_REPLACE;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_SEMICOLON)) {
            self->mode = MODE_COMMAND;
        }

        if (IsKeyPressed(KEY_V)) {
            self->mode = MODE_VISUAL;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_V)) {
            self->mode = MODE_VISUAL_LINE;
        }
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_V)) {
            self->mode = MODE_VISUAL_BLOCK;
        }
    }

    if (self->mode == MODE_COMMAND_LINE && IsKeyPressed(KEY_ESCAPE)) {
        self->mode = MODE_COMMAND;
    }

    if (self->mode != MODE_NORMAL && self->mode != MODE_COMMAND_LINE && IsKeyPressed(KEY_ESCAPE)) {
        self->mode = MODE_NORMAL;
    }

    if (self->mode == MODE_COMMAND && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_ONE)) {
        self->mode = MODE_COMMAND_LINE;
    }
}
