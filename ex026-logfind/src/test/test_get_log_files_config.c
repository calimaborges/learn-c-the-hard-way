#include "../get_log_files_config.h"
#include <assert.h>

#define TEST_CONFIG_PATH "./src/test"

int main(int argc, char **argv) {
  printf("\n");
  printf("Test get_log_files_config.c\n");
  char log_files[MAX_LINES][MAX_PATH_LENGTH];

  // Test 1: Config file contains 5 entries
  setenv("XDG_CONFIG_HOME", TEST_CONFIG_PATH, 1);
  int result = get_log_files_config(log_files);
  assert(result != -1);
  assert(strcmp(log_files[0], "/tmp/file1") == 0);
  assert(strcmp(log_files[1], "/tmp/file2") == 0);
  assert(strcmp(log_files[2], "/tmp/file3") == 0);
  assert(strcmp(log_files[3], "/tmp/file4") == 0);
  assert(strcmp(log_files[4], "/tmp/file5") == 0);
  printf("Test 1 passed: Config file exists\n");

  printf("All tests passed successfully.\n");
  return 0;
}
