#include "get_log_files_config.h"

int get_log_files_config(char (*return_logfiles)[MAX_PATH_LENGTH]) {
  char config_path[MAX_PATH_LENGTH];
  int result = get_config_path(&config_path);
  check(result == 0, "Could not open config file");
  FILE* file = fopen(config_path, "r");
  check(file != NULL, "Error opening file");
  int line_count = 0;
  while (fgets(return_logfiles[line_count], MAX_PATH_LENGTH, file) != NULL && line_count < MAX_LINES) {
    return_logfiles[line_count][strcspn(return_logfiles[line_count], "\n")] = '\0';
    line_count++;
  }
  fclose(file);
  return line_count;
error:
  fclose(file);
  return -1;
}
