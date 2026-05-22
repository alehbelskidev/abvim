#include "info_line.h"

#include <raylib.h>

#include "layout.h"

BlockLayout IL_Draw(EditorConfig* config, const BlockLayout boundries)
{
    float sizeY = 30;
    float sizeX = GetScreenWidth() - boundries.padding.x * 2;
    float offsetX = boundries.offset.x + boundries.padding.x;
    float offsetY =
        (boundries.offset.y + GetScreenHeight()) - boundries.padding.y - sizeY;

    DrawRectangleRounded((Rectangle){offsetX, offsetY, sizeX, sizeY},
                         config->roundness - 0.1, config->segments,
                         config->theme.secondary);
    DrawRectangleRoundedLinesEx((Rectangle){offsetX, offsetY, sizeX, sizeY},
                                config->roundness, config->segments,
                                config->lineThick, config->theme.tertiary);

    return (BlockLayout){.offset = {offsetX, offsetY},
                         .padding = {0, 0},
                         .size = {sizeX, sizeY}};
}
