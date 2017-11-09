//
// Created by user on 11/9/17.
//

#include <jni.h>
#include <string>
#include <vector>

using namespace std;

extern "C"{

JNIEXPORT jstring JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_stringFromJNI(JNIEnv *env, jobject jobject1)
{
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jobjectArray JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_getAllProcessPid(JNIEnv*env, jobject obj)
{

    //Create a vector (an array) of Strings and add items to it
    vector<string>vec;

    vec.push_back("Ranjan.B.M");
    vec.push_back("Nipuna Rajapaksha");
    vec.push_back("Preetham.S.N");
    vec.push_back("Karthik.S.G");

    //Instantiate your object Array and return it!
    jclass clazz = (env)->FindClass("java/lang/String");
    jobjectArray objarray = (env)->NewObjectArray(vec.size() ,clazz ,0);

    for(int i = 0; i < vec.size(); i++) {
        string s = vec[i];
        jstring js = (env)->NewStringUTF(s.c_str());
        (env)->SetObjectArrayElement(objarray , i , js);
    }

    return objarray;

}

};