# gzsize(1) -- Get the uncompressed size of an archive

## SYNOPSIS

`gzsize` <file> [<file> ...]

## DESCRIPTION

Print the uncompressed size of a GZipped file. If multiple files are given,
print the total size of all of them. `-` reads on stdin.

## OPTIONS

  * `-h`:
    Print the help and exit.

  * `-H`:
    Output a human-readable size, like "263M".

  * `-v`:
    Print the version and exit.


## EXAMPLES

  * Get the uncompressed size of a file:
    `gzsize myfile.gz`

  * Get the uncompressed size of stdin:
    `curl https://example.com/somefile.gz | gzsize -`

## AUTHOR

Written by Baptiste Fontaine <<b@ptistefontaine.fr>\>.

## BUGS

Bugs should be reported at <https://github.com/bfontaine/gzsize/issues>.

## SEE ALSO

The project homepage is at <https://github.com/bfontaine/gzsize>.
