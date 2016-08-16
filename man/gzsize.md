# gzsize(1) -- Get the uncompressed size of an archive

## SYNOPSIS

`gzsize` <file> [<file> ...]

## DESCRIPTION

Print the uncompressed size of a GZipped file. If multiple files are given,
print the total size of all of them.

## OPTIONS

  * `-h`:
    Print the help and exit

  * `-H`:
    Output an human-readable size

  * `-v`:
    Print the version and exit


## EXAMPLES

  * Check a file:
    `gzsize myfile.gz`

## AUTHOR

Written by Baptiste Fontaine <<b@ptistefontaine.fr>\>.

## BUGS

Bugs should be reported at <https://github.com/bfontaine/gzsize/issues>.

## SEE ALSO

The project homepage is at <https://github.com/bfontaine/gzsize>.
