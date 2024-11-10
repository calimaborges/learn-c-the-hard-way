#include "dbg.h"
#include <stdlib.h>

#define DEFAULT_CONFIG_HOME ".config"
#define MAX_PATH_LENGTH 1024
#define MAX_LINES 1000

int get_config_path(char (*config_path)[MAX_PATH_LENGTH]);
