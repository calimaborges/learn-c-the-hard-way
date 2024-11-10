#include "config.h"

int get_config_path(char (*config_path)[MAX_PATH_LENGTH]) {
  char *xdg_config = getenv("XDG_CONFIG_HOME");
  if (xdg_config != NULL) {
    strcpy(*config_path, xdg_config);
    strcat(*config_path, "/logfind.conf");
    check_mem(config_path);
    return 0;
  }
  char *home = getenv("HOME");
  check(home != NULL, "HOME environment variable is not set.");
  strcpy(*config_path, home);
  strcat(*config_path, "/.config/logfind.conf");
  return 0;
error:
  return -1;
}
