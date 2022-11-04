#!/bin/bash

echo 'find a dir'

echo 'please a dir'
read dir
echo "$dir"
echo 'please a file'
read file
echo "$file"
echo  "$dir/$file"

if [ -d $dir ];then
    echo "dir is exit"
    if [ -f $dir/$file ];then
	    echo "file is exit"
    else
	    echo " file in $dir will be created"
	    touch $dir/$file
    fi
else
	echo " file in this $dir will be created"
	touch $dir/$file
fi



