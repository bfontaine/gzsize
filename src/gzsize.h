#ifndef _GZSIZE
#define _GZSIZE 1

enum {
        CHUNK = 1048576
};

/**
 * Decompress an input stream on /dev/null and compute its decompressed size.
 **/
long get_size(int fd);

#endif
