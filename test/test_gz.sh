#! /bin/bash

FILE=x2_ceRc-a12.tmp

echo -n 'foobarwqz' > $FILE
size=$(wc -c $FILE | awk '{print $1}')

gzip $FILE

res=$($GZSIZE ${FILE}.gz)
if [ "$res" -ne "$size"]; then
    exit 1
fi
rm -f ${FILE}.gz
