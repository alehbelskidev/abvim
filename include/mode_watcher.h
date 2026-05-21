#ifndef MODE_WATCHER_H
#define MODE_WATCHER_H

typedef enum {
    MODE_NORMAL,
    MODE_INSERT,
    MODE_REPLACE,
    MODE_VISUAL,
    MODE_VISUAL_BLOCK,
    MODE_VISUAL_LINE,
    MODE_COMMAND,
    MODE_COMMAND_LINE,

    MODE_WELCOME,
    MODE_OPEN,
} Mode;

typedef struct {
    Mode mode;
} ModeWatcher;

ModeWatcher* MW_Init();
void MW_FREE(ModeWatcher* mw);
void MW_HandleModeChange(ModeWatcher* mw);

#endif  // !MODE_WATCHER_H
