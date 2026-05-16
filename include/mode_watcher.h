#ifndef MODE_WATCHER_H
#define MODE_WATCHER_H

#include <raylib.h>

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

ModeWatcher* MW_New();
void MW_Free(ModeWatcher* mw);
void MW_SetMode(ModeWatcher* self, Mode m);
void MW_Draw(ModeWatcher* self);

#endif  // !MODE_WATCHER_H
