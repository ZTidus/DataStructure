#!/bin/bash

# generate markdown template file


name=$1

suffix=${name##*.}
filename=$(echo $name | cut -d '.' -f1)

if [ $suffix -eq "md" ]; then
  # do nothing
  new_name=$filename".md"

else
  new_name=$name".md"
fi

# get file name
md_name=$(basename $name)
# remove file suffix
new_md_name=${md_name%.*}

# check if name is empty
if [ ! $name ];
  then echo "input file name."
  exit -1
fi

# add template info
echo "
# "$new_md_name"
type:

difficulty:

---

## [Problem Info][problem_link]

## Attention

## Answer - 1

- java

- time: ms
- beat %
- big O:

## Answer - 2

- java

- time: ms
- beat %
- big O:

[problem_link]:
" > "$new_name"

if [ $? == 0 ]; then
  echo "$new_md_name.md has been created."
fi
echo "done."
