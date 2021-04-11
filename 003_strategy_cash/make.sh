#!/bin/bash
rm -rf build
mkdir build; cd build; cmake ..
make -j
if [ $? -eq 0 ];
then
	echo "compile passed"
else
	echo "compile failed"
	exit
fi

echo -e "\n-------------->>run..."
./hello
