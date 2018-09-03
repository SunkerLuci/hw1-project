#!/bin/bash

# 获取当前路径
currentDir=$(dirname $0)
# 获取apk路径
apkDir=$currentDir"apk/app-debug.apk"

echo $apkDir

path=""

subDir=""

# 定义读取目录函数
function readDir(){

   cd $apkDir

   filelist=`ls ./`

   for file in $filelist

   do

       installApk $file

   done

}
# 定义安装Apk函数
function installApk(){

   file=$1

   extension="${file##*.}"

   if [ "$extension" = "apk" ]

   then
       adb install $file
       cd /usr/bin              
       ./.apk

   else

       echo "Error:"$file "is not apk file."

   fi

}
# 读取目录
readDir $apkDir
