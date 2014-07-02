#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "gzsize.h"
#include "version.h"
#include "cli.h"

int print_help(char *exe) {
        printf("Usage:\n"
               "\t%s [<options>] <file>\n"
               "\n"
               "Options:\n"
               "\t-h: show this help and exit\n"
               "\t-H: human-readable size output\n"
               "\t-v: print the version and exit\n"
               "\n", exe);
        return 0;
}

int print_version(void) {
        printf("gzsize(1) - version %s\n", GZSIZE_VERSION);
        return 0;
}

void print_size(long size, char human) {
        int i;

        if (size < 1024 || !human) {
                printf("%ld bytes\n", size);
                return;
        }

        i = 0;
        while (size > 1024 && i < SIZE_SUFFIXES_COUNT) {
                i++;
                size /= 1024;
        }

        printf("%ld%c\n", size, SIZE_SUFFIXES[i]);
}

int main(int argc, char **argv) {

        int fd;
        long size;

        int optch;
        extern int opterr;

        char human_readable_flag = 0;

        opterr = 1;

        while ((optch = getopt(argc, argv, "hHv")) != -1) {
                switch (optch) {
                case 'h':
                        return print_help(argv[0]);
                case 'H':
                        human_readable_flag = 1;
                        break;
                case 'v':
                        return print_version();
                case '?':
                        /* wrong option or missing argument */
                        exit(EXIT_FAILURE);
                }
        }

        /* No arguments */
        if (optind == argc) {
                return print_help(argv[0]);
        }

        fd = open(argv[optind], O_RDONLY);
        if (fd == -1) {
                perror("open");
                return -1;
        }

        size = get_size(fd);

        if (size < 0) {
                return size;
        }

        print_size(size, human_readable_flag);

        return 0;
}
