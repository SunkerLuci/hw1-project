LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := client
LOCAL_SRC_FILES := client.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := jniClient
LOCAL_SRC_FILES := service.cpp
LOCAL_SHARED_LIBRARIES := client
LOCAL_LDLIBS :=-llog
include $(BUILD_SHARED_LIBRARY)