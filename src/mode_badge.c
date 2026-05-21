#include "mode_badge.h"

#include <raylib.h>
#include <stdbool.h>

#include "editor_config.h"
#include "layout.h"
#include "mode_watcher.h"

// FYI: not covered by theme, find out how
static const ModeStyle MODE_STYLES[] = {
    // Read/Write
    [MODE_NORMAL] = {.bg = {97, 175, 239, 255}, .fg = {40, 44, 52, 255}, .label = "Normal"},
    [MODE_INSERT] = {.bg = {198, 120, 221, 255}, .fg = {40, 44, 52, 255}, .label = "Insert"},
    [MODE_REPLACE] = {.bg = {224, 108, 117, 255}, .fg = {40, 44, 52, 255}, .label = "Replace"},
    [MODE_VISUAL] = {.bg = {229, 192, 123, 255}, .fg = {40, 44, 52, 255}, .label = "Visual"},
    [MODE_VISUAL_BLOCK] = {.bg = {209, 154, 102, 255}, .fg = {40, 44, 52, 255}, .label = "V-Block"},
    [MODE_VISUAL_LINE] = {.bg = {235, 203, 139, 255}, .fg = {40, 44, 52, 255}, .label = "V-Line"},
    [MODE_COMMAND] = {.bg = {152, 195, 121, 255}, .fg = {40, 44, 52, 255}, .label = "Command"},
    [MODE_COMMAND_LINE] = {.bg = {86, 182, 194, 255}, .fg = {40, 44, 52, 255}, .label = "Cmd-Line"},

    // System
    [MODE_WELCOME] = {.bg = {200, 200, 210, 255}, .fg = {40, 44, 52, 255}, .label = "Welcome"},
    [MODE_OPEN] = {.bg = {200, 200, 210, 255}, .fg = {40, 44, 52, 255}, .label = "Open"},
};

BlockLayout MB_Draw(const EditorConfig* config, const BlockLayout boundries, Mode mode)
{
    ModeStyle modeStyle = MODE_STYLES[mode];
    Vector2 fontSize = MeasureTextEx(config->font, modeStyle.label, config->fontSize, 0);
    float paddingX = fontSize.x * 0.5f;
    float paddingY = paddingX / 2.0f;
    float blockH = boundries.size.y;
    float blockW = fontSize.x + paddingX;

    BlockLayout layout = {
        .padding = {paddingX, paddingY},
        .size = {blockW, blockH},
        .offset = {boundries.offset.x, boundries.offset.y},
    };

    Rectangle rect = {layout.offset.x, layout.offset.y, layout.size.x, layout.size.y};
    DrawRectangleRounded(rect, config->roundness, config->segments, modeStyle.bg);

    Vector2 textPos = {layout.offset.x + layout.padding.x / 2,
                       layout.offset.y + (layout.size.y / 2) - (fontSize.y / 2)};
    DrawTextEx(config->font, modeStyle.label, textPos, config->fontSize, 0, modeStyle.fg);

    return layout;
}
