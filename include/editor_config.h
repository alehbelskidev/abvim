#ifndef EDITOR_CONFIG_H
#define EDITOR_CONFIG_H

typedef struct {
    char fontPath[512];
    int fontSize;
} EditorConfig;

EditorConfig* EC_Init();
void EC_FREE(EditorConfig* ec);

void EC_SetFontSize(int fs);
void EC_SetFontPath(char* ff);

#endif  // !EDITOR_CONFIG_H
