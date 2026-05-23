#include <raylib.h>

#include "ctx.h"
#include "editor_config.h"
#include "layout.h"

void WS_Init();
void WS_FREE();

BlockLayout WS_Draw(const EditorConfig* config, const Context* ctx,
                    BlockLayout boundries);
