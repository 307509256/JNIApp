//
// Created by user on 11/9/17.
//

#include <jni.h>
#include <string>

extern "C"{

    JNIEXPORT jstring JNICALL
    Java_com_example_nsbr_hellojniapp_MainActivity_stringFromJNI(JNIEnv *env, jobject jobject1)
    {
        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }


};