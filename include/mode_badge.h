#ifndef MODE_BADGE_H
#define MODE_BADGE_H

#include <raylib.h>
#include <stdbool.h>

#include "editor_config.h"
#include "layout.h"
#include "mode_watcher.h"

typedef struct {
    Color bg;
    Color fg;
    const char* label;
} ModeStyle;

BlockLayout MB_Draw(const EditorConfig* config, BlockLayout boundries, Mode mode);

#endif  // !MODE_BADGE_H
