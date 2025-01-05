#!/bin/sh

if [ "$#" -ne 2 ]
then
	echo "parameters are not defined as expected"
	exit 1
fi

filesdir=$1
searchstr=$2

if ! [ -d "${filesdir}" ]
then
	echo "not a directory"
	exit 1
fi

filescount=$(find "${filesdir}" -type f | wc -l)
linescount=$(find "${filesdir}" -type f | xargs grep "${searchstr}" -o | wc -l)

echo "The number of files are ${filescount} and the number of matching lines are ${linescount}"
exit 0
