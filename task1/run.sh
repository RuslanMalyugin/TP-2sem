#!/bin/bash
mkdir $3
find $1 -name "*.$2" -exec cp --parents {} $3 \;
tar -zcf $4 $3
echo done
