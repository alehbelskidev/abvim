#ifndef CTX_H
#define CTX_H

#include <raylib.h>

#include "layout.h"

typedef struct {
    BlockLayout root;
    Vector2 mousePos;
    Vector2 mouseDelta;
} Context;

Context* CTX_Init();
void CTX_FREE(Context* ctx);

#endif  // !CTX_H
