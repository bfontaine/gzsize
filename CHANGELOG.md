# GZSize Changelog

## 0.1.3 (2018/08/15)

* Fix overflow of reported size above ~2GB (contributed by [@julianoes][])

[@julianoes]: https://github.com/julianoes

## 0.1.2 (2017/12/24)

* Print errors on stderr instead of stdout
* Print the help when passed a wrong option
* Fix a typo in the doc

## 0.1.1 (2016/08/20)

* Close files when done. When passing a lot of files as arguments one would get
  `open: Too many open files` as an error. This fixes that.

## 0.1.0 (2016/08/16)

* Allow to pass multiple files on the command-line.
* Use an `unsigned long long` for the size instead of a `long`. This allows
  sizes up to 2^64 (i.e. more than one exabyte) instead of 2^16.

## 0.0.1 (2014/07/02)

Initial release.
