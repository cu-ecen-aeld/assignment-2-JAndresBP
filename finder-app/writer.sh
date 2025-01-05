#!/bin/sh

if [ "$#" -ne 2 ]
then
	echo "parameters are not defined as expected"
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")" && touch $writefile

if ! [ "$?" -eq 0 ]
then
	echo "an error occurred creating the file"
	exit 1
fi

echo "${writestr}" > "${writefile}"

if [ "$?" -eq 0 ]
then
	echo "operation succeed"
	exit 0
else
	echo "an error occurred writting the file"
	exit 1
fi
