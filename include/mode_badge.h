#ifndef MODE_BADGE_H
#define MODE_BADGE_H

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
} ModeBadge;

void MB_Init(EditorConfig* c);
void MB_FREE();

void MB_SetMode(Mode m);
void MB_Calc(const EditorConfig* c, LayoutContext* ctx);
bool MB_ShouldReCalc();
void MB_Draw(const EditorConfig* c);
void MB_KeyEvent();

#endif  // !MODE_BADGE_H
