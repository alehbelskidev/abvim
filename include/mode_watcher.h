#ifndef MODE_WATCHER_H
#define MODE_WATCHER_H

#include <raylib.h>
#include <stdbool.h>

#include "editor_config.h"
#include "layout.h"

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

    BlockLayout layout;
    Vector2 fontSize;
    bool isDirty;
    float roundness;
    int segments;
} ModeWatcher;

void MW_Init(EditorConfig* c);
void MW_FREE();

void MW_SetMode(Mode m);
void MW_Calc(const EditorConfig* c, LayoutContext* ctx);
bool MW_ShouldReCalc();
void MW_Draw(const EditorConfig* c);
void MW_KeyEvent();

#endif  // !MODE_WATCHER_H
