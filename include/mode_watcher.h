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

void MW_HandleModeChange();
Mode MW_GetMode();

#endif  // !MODE_WATCHER_H
