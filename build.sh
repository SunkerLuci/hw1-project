#!/bin/sh

projectRootPath=$(dirname $0)
envPath=$projectRootPath"/envs"
distPath=$projectRootPath"/dist"

cServiceRootPath=$projectRootPath"src/service"
apkRootPath=$projectRootPath"src/apk"
initPatchPath=$projectRootPath"/platform_tools/init.rc.patch"
initRCPath="out/target/product/generic/root"
ramdsikPath=$projectRootPath"/platform_tools/"
ramdsikMountPath=$projectRootPath"/ramdisk"
systemMountPath=$projectRootPath"/system"

# 获取平台相关的环境变量
version="26"
if [$1 = "26"]
then 
    version=$1
elif [$1 = "27"]
    version=$1
fi
fi

$envPath$version".sh"

# 编译C服务
cd $cServiceRootPath
camke .
make
cp $cServiceRootPath"/c_service" $distPath
# 编译APK
cd $apkRootPath
gradle gradlew
cp $apkDir"/app-debug.apk" $distPath
# 解包ramdisk.img, system.img
mount -o rw,loop ramdisk.img $ramdsikPath
mount -o rw,loop system.img $systemPath
# 给init.rc打补丁
patch -p0 < $initPatchPath
# 复制C服务进img
cp $distPath"/c_service" $systemMountPath"/bin/"
# 复制apk进img
cp $distPath"/app-debug.apk" $systemPath"/apk/"
# 打包输出img
unmount $ramdsikPath
unmount $systemPath
