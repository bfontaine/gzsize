#ifndef _GZSIZE_H
#define _GZSIZE_H 1

#define SIZE_SUFFIXES "\0kMGTP"
#define SIZE_SUFFIXES_COUNT 6

/**
 * Print an help text.
 * - exe: the name of the executable for this program. This should be argv[0].
 **/
int print_help(char *exe);

/** Print the current version **/
int print_version(void);

/**
 * Print a size. `human` should be set to `1` for an human-readable string, `0`
 * for the raw bytes count.
 **/
void print_size(long size, char human);

#endif
