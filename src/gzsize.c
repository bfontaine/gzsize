#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#include "gzsize.h"


long get_size(int fd) {
        int ret, flush;
        z_stream strm;
        unsigned char in[CHUNK];
        unsigned char out[CHUNK];

        strm.zalloc = Z_NULL;
        strm.zfree = Z_NULL;
        strm.opaque = Z_NULL;
        strm.avail_in = 0;
        strm.next_in = Z_NULL;

        ret = inflateInit2(&strm, 32+MAX_WBITS);
        if (ret != Z_OK) {
                printf("Initialization error (%d)\n", ret);
                return ret;
        }

        do {
                strm.avail_in = read(fd, in, CHUNK);
                if (strm.avail_in == (uInt)-1) {
                        perror("read");
                        inflateEnd(&strm);
                        return Z_ERRNO;
                }
                if (strm.avail_in == 0) {
                        break;
                }

                flush = strm.avail_in == (uInt)EOF ? Z_FINISH : Z_NO_FLUSH;
                strm.next_in = in;

                do {
                        strm.avail_out = CHUNK;
                        strm.next_out = out;
                        ret = inflate(&strm, flush);

                        if (ret < 0 && ret != Z_BUF_ERROR) {
                                printf("Error: %s (%d)\n", strm.msg, ret);
                                inflateEnd(&strm);
                                return -1;
                        }
                } while (strm.avail_out == 0);


        } while (ret != Z_STREAM_END);

        inflateEnd(&strm);
        return strm.total_out;
}



int main(int argc, char **argv) {

        int fd;
        long size;

        if (argc != 2) {
                printf("Usage:\n\t%s <file>\n", argv[0]);
                return -1;
        }

        fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
                perror("open");
                return -1;
        }

        size = get_size(fd);

        if (size < 0) {
                return size;
        }

        printf("%ld bytes.\n", size);

        return 0;
}
