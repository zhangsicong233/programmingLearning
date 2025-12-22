#! /bin/bash

echo "the number of lines is $(wc -l $1 | cut -d ' ' -f 1)"
echo "the number of words is $(wc -w $1 | cut -d ' ' -f 1)"