CFLAGS=-Wall -g
build:
	mkdir -p dist/release
	cc -c -o dist/release/config.o src/config.c
	cc -c -o dist/release/get_log_files_config.o src/get_log_files_config.c
	cc src/main.c dist/release/config.o dist/release/get_log_files_config.o -o dist/release/logfind
clean:
	rm -rf dist
test:
	mkdir -p dist/test
	cc -c -o dist/test/config.o src/config.c
	cc -c -o dist/test/get_log_files_config.o src/get_log_files_config.c
	cc src/test/test_config.c dist/test/config.o -o dist/test/test_config
	cc src/test/test_get_log_files_config.c \
		dist/test/config.o \
		dist/test/get_log_files_config.o \
		-o dist/test/test_get_log_files_config
	./dist/test/test_config
	./dist/test/test_get_log_files_config
