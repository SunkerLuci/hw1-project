package com.example.wenwen1zhang.myapp;

public class NativeClass {
    public static native boolean getServiceFromJNI();
    static {
        System.loadLibrary("jniClient");
    }
}