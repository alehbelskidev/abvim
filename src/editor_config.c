#include "editor_config.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void joinPath(char* path, size_t size)
{
    const char* configdir = "/.config/abvim/config.ini";
    const char* homedir = getenv("HOME");
    snprintf(path, size, "%s%s", homedir, configdir);
}

void readFileToConfig(EditorConfig* ec, FILE* f)
{
    fscanf(f, " font_path = %s", ec->fontPath);
    printf("EditorConfig::fontPath=%s\n", ec->fontPath);
    fscanf(f, " font_size = %d", &ec->fontSize);
    printf("EditorConfig::fontSize=%d\n", ec->fontSize);
}

EditorConfig* EC_Init()
{
    EditorConfig* ec = malloc(sizeof(EditorConfig));

    if (ec != NULL) {
        ec->theme = (Theme){
            .neutral = {12, 12, 14, 255},
            .primary = {228, 228, 231, 255},
            .secondary = {39, 39, 42, 255},
            .tertiary = {82, 82, 91, 255},
        };

        char path[512];
        joinPath(path, sizeof(path));
        FILE* file = fopen(path, "r");
        printf("EditorConfig:: path - %s\n", path);

        if (file != NULL) {
            printf("EditorConfig:: Reading from file\n");
            readFileToConfig(ec, file);
            fclose(file);
        } else {
            printf("EditorConfig:: Using default values\n");
            ec->fontSize = 14;
        }
    }

    return ec;
}

void EC_LoadFont(EditorConfig* ec)
{
    ec->font = LoadFontEx(ec->fontPath, ec->fontSize * 2, NULL, 0);
    SetTextureFilter(ec->font.texture, TEXTURE_FILTER_BILINEAR);
}

void EC_UnloadFont(EditorConfig* ec)
{
    UnloadFont(ec->font);
}

void EC_FREE(EditorConfig* ec)
{
    if (ec != NULL) {
        free(ec);
    }
}
