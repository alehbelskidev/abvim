#ifndef MODE_WATCHER_H
#define MODE_WATCHER_H

#include <raylib.h>

#include "editor_config.h"

typedef enum {
    MODE_NORMAL,
    MODE_INSERT,
    MODE_REPLACE,
    MODE_VISUAL,
    MODE_VISUAL_BLOCK,
    MODE_VISUAL_LINE,
    MODE_COMMAND,
    MODE_COMMAND_LINE,
} Mode;

typedef struct {
    Color bg;
    Color fg;
    const char* label;
} ModeStyle;

typedef struct {
    Mode mode;
    ModeStyle modeStyle;
} ModeWatcher;

void MW_Init();
void MW_FREE();

void MW_SetMode(Mode m);
void MW_Draw(const EditorConfig* ec);

#endif  // !MODE_WATCHER_H
