#!/usr/bin/env sh

sh foo.sh
exit_code=$?
if [ ! $exit_code -eq 0 ]
then
    echo "bad"
    exit $exit_code
else
    echo "good"
fi


