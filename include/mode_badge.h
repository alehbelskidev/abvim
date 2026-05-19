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

typedef struct {
    ModeStyle modeStyle;
    Mode mode;
    BlockLayout layout;
    Vector2 fontSize;
    bool isDirty;
    float roundness;
    int segments;
} ModeBadge;

void MB_Init(EditorConfig* c, ModeWatcher* mw);
void MB_FREE();

void MB_SetMode(Mode m);
void MB_Calc(const EditorConfig* c, LayoutContext* ctx);
bool MB_ShouldReCalc();
void MB_Draw(const EditorConfig* c);

#endif  // !MODE_BADGE_H
