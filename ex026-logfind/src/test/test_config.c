#include "../config.h"
#include <assert.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("\n");
  printf("Test config.c\n");
  char config_path[MAX_PATH_LENGTH] = "";

  // Test 1: When XDG_CONFIG_HOME is set
  setenv("XDG_CONFIG_HOME", "/custom/config", 1);
  int result = get_config_path(&config_path);
  assert(result == 0);
  assert(strcmp(config_path, "/custom/config/logfind.conf") == 0);
  printf("Test 1 passed: XDG_CONFIG_HOME is set\n");
  config_path[0] = '\0';

  // Test 2: When XDG_CONFIG_HOME is not set, but HOME is set
  unsetenv("XDG_CONFIG_HOME");
  setenv("HOME", "/home/user", 1);
  result = get_config_path(&config_path);
  assert(result == 0);
  assert(strcmp(config_path, "/home/user/.config/logfind.conf") == 0);
  printf("Test 2 passed: XDG_CONFIG_HOME not set, using HOME\n");
  config_path[0] = '\0';

  // Test 3: When both XDG_CONFIG_HOME and HOME are not set
  unsetenv("XDG_CONFIG_HOME");
  unsetenv("HOME");
  result = get_config_path(&config_path);
  assert(result == -1);
  printf("Test 3 passed: Neither XDG_CONFIG_HOME nor HOME are set\n");

  printf("All tests passed successfully.\n");
  return 0;
}
