#ifndef EDITOR_CONFIG_H
#define EDITOR_CONFIG_H

#include <raylib.h>

typedef struct {
    Color neutral;
    Color primary;
    Color secondary;
    Color tertiary;
} Theme;

typedef struct {
    Font font;
    char fontPath[512];
    int fontSize;
    Theme theme;
} EditorConfig;

EditorConfig* EC_Init();
void EC_FREE(EditorConfig* ec);

void EC_SetFontSize(int fs);
void EC_SetFontPath(char* ff);
void EC_LoadFont(EditorConfig* ec);
void EC_UnloadFont(EditorConfig* ec);

#endif  // !EDITOR_CONFIG_H
