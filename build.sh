#!/bin/sh
 
if [ $# != 1 ]
then
     echo "Usage: test.sh cname"
     echo "cname:the name of .c file"
else
     echo "The executable file name is:" $1
     gcc -o $1 $1.c
     ./$1	

set -e
BUILD_DIR=`pwd`
WORKING_DIR="${BUILD_DIR}/src"
DIST_DIR="${BUILD_DIR}/dist"
cd pwd/src/Service
make>dist
cd pwd/src/apk
make>dist
CONFIG_FILE="${BUILD_DIR}/config.json"

get_value_by_key() {
    JSON_FILE=${CONFIG_FILE}
    KEY=${1}
    JSON_VALUE=$(cat ${JSON_FILE} | jq .${KEY} | sed 's/\"//g')
    echo "${JSON_VALUE}"
}
fi
