#ifndef LAYOUT_H
#define LAYOUT_H

#include <raylib.h>
#include <stdbool.h>

typedef struct {
    Vector2 padding;
    Vector2 offset;
    Vector2 size;
    Vector2 maxSize;
} BlockLayout;

typedef struct {
    BlockLayout layout;
} LayoutContext;

LayoutContext* CTX_Init();
void CTX_FREE(LayoutContext* ctx);

void CTX_Update(LayoutContext* ctx);
bool CTX_ShouldUpdate(LayoutContext* ctx);

#endif  // !LAYOUT_H
