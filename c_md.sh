#/bin/bash

# generate markdown template file


name=$1
md_name=$(basename $name)
if [ ! $name ];
  then echo "input file name."
  exit -1
fi

echo "
# "$md_name"
type:

---

## Problem Info

## Answer

## Attention

" > $1.md

echo "done."