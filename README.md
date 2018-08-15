# GZSize

**GZSize** is a lightweight tool to measure the decompressed size of a GZip’d
file.

It works by decompressing it on the fly but doesn’t write the data which means
you can test any file size without worrying for your disk usage.

## Install

### From source

    git clone https://github.com/bfontaine/gzsize.git
    cd gzsize
    [sudo] make install

Dependencies :

* `zlib`

### With [Homebrew][]/[Linuxbrew][]

    brew install bfontaine/utils/gzsize

[Homebrew]: https://brew.sh/
[Linuxbrew]: http://linuxbrew.sh/

## Usage

    $ gzsize <file.gz> [<file.gz> ...]

Check also the [man page][man].

[man]: https://bfontaine.github.io/gzsize/
