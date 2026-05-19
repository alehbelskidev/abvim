#ifndef LAYOUT_H
#define LAYOUT_H

#include <raylib.h>
#include <stdbool.h>

typedef struct {
    Vector2 padding;
    Vector2 offset;
    Vector2 size;
} BlockLayout;

typedef struct {
    float screenW;
    float screenH;
    float infoLineH;
    Vector2 infoLIneOffset;
} LayoutContext;

LayoutContext* CTX_Init();
void CTX_FREE(LayoutContext* ctx);

void CTX_Update(LayoutContext* ctx);
bool CTX_ShouldUpdate(LayoutContext* ctx);

#endif  // !LAYOUT_H
