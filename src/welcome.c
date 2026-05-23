#include "welcome.h"

#include <raylib.h>

#include "editor_config.h"
#include "layout.h"

const char* MENU_ITEMS[3] = {"Open File/Directory", "Config",
                             "Recent Projects"};

static Texture2D logoTexture;

void WS_Init()
{
    Image logoImg = LoadImage("./assets/logo.png");
    logoTexture = LoadTextureFromImage(logoImg);
    UnloadImage(logoImg);
}

void WS_FREE()
{
    UnloadTexture(logoTexture);
}

BlockLayout WS_Draw(const EditorConfig* config, BlockLayout boundries)
{
    BlockLayout blockLayout = {{16, 16}, {0, 0}, {0, 0}};
    Vector2 logoSize = {logoTexture.width, logoTexture.height};

    Vector2 fonts[3];
    Vector2 menuBlockSize = {0, 0};
    for (int i = 0; i < 3; i++) {
        Vector2 fontSize =
            MeasureTextEx(config->font, MENU_ITEMS[i], config->fontSize, 0);
        fonts[i] = fontSize;
        menuBlockSize.y += fontSize.y;
        if (fontSize.x > menuBlockSize.x) {
            menuBlockSize.x = fontSize.x;
        }
    }

    if (logoSize.x > menuBlockSize.x) {
        blockLayout.size.x = logoSize.x;
    } else {
        blockLayout.size.x = menuBlockSize.x;
    }
    blockLayout.size.x += blockLayout.padding.x * 2;
    blockLayout.size.y =
        logoSize.y + 16 + menuBlockSize.y + 8 * 2 + blockLayout.padding.y * 2;

    blockLayout.offset.x = boundries.size.x / 2 - blockLayout.size.x / 2;
    blockLayout.offset.y = boundries.size.y / 2 - blockLayout.size.y / 2;

    DrawRectangleRec((Rectangle){blockLayout.offset.x, blockLayout.offset.y,
                                 blockLayout.size.x, blockLayout.size.y},
                     config->theme.secondary);
    DrawRectangleLinesEx((Rectangle){blockLayout.offset.x, blockLayout.offset.y,
                                     blockLayout.size.x, blockLayout.size.y},
                         config->lineThick, config->theme.tertiary);

    float logoPosX = blockLayout.offset.x +
                     (blockLayout.size.x / 2 - (float)logoTexture.width / 2) -
                     blockLayout.padding.x;
    float logoPosY = blockLayout.offset.y + blockLayout.padding.y;
    DrawTexture(logoTexture, logoPosX, logoPosY, WHITE);

    float textStartY = logoPosY + 16 + (float)logoTexture.height;
    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            textStartY += 8;
        }
        Vector2 textPos = {
            blockLayout.offset.x + (blockLayout.size.x / 2) - fonts[i].x / 2,
            textStartY + (fonts[i].y * i)};
        DrawTextEx(config->font, MENU_ITEMS[i], textPos, config->fontSize, 0,
                   config->theme.primary);
    }

    return blockLayout;
}
