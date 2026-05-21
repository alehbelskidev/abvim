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

#endif  // !LAYOUT_H
