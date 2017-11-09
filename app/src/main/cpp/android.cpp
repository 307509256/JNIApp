//
// Created by user on 11/9/17.
//

// android.cpp

#include <jni.h>
#include "Time.cpp"

extern "C" {

JNIEXPORT jint JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_getDay(JNIEnv *env, jobject jobject1, jint year, jint month, jint day)
{

    Time date(year, month, day);

    return date.getDay();
}


};