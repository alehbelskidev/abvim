#ifndef INFO_LINE_H
#define INFO_LINE_H

#include <raylib.h>

#include "editor_config.h"
#include "layout.h"

typedef struct {
    float roundness;
    float lineThick;
    int segments;
    BlockLayout layout;
} InfoLine;

void IL_Init(EditorConfig* c);
void IL_FREE(InfoLine* il);

void IL_Calc(EditorConfig* c, LayoutContext* ctx);
void IL_Draw(EditorConfig* c);

#endif  // !INFO_LINE_H
