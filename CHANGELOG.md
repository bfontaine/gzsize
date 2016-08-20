# GZSize Changelog

## 0.1.1 (2016/08/20)

* Close files when done. When passing a lot of files as arguments one would get
  `open: Too many open files` as an error. This fixes that.

## 0.1.0 (2016/08/16)

* Allow to pass multiple files on the command-line.
* Use an `unsigned long long` for the size instead of a `long`. This allows
  sizes up to 2^64 (i.e. more than one exabyte) instead of 2^16.

## 0.0.1 (2014/07/02)

Initial release.
