//
// Created by wenwen1.zhang on 2018/9/2.
//

#include<jni.h>

jstring Java_com_example_wenwen1zhang_myapp_NativeClass_getServiceFromJNI(JNIEnv *env,jobject thiz){
    return (*env)->NewStringUTF(env,"I am Str from jni by call binderService!");
}