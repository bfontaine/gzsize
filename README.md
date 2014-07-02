# GZSize

**GZSize** is a lightweight tool to measure the decompressed size of a GZip’d
file.

It works by decompressing it on the fly but doesn’t write the data which means
you can test any file size without worrying for your disk usage.

## Install

    git clone https://github.com/bfontaine/gzsize.git
    cd homer
    [sudo] make install

Dependencies :

* `zlib`

## Usage

    $ gzsize <file.gz>

Check also the [man page][man].

[man]: https://bfontaine.github.io/gzsize/
