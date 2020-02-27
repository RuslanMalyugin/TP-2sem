#!/bin/bash

find $1 -name "*.$2" | tar -cf $4 -P -T -
echo done
