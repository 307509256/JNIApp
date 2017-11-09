#include <jni.h>


int getFacetCount(JNIEnv *env, jobject obj) {
    jclass cls = env->GetObjectClass(obj);
    jmethodID methodId = env->GetMethodID(cls, "getFacetCount", "()I");
    int result = env->CallIntMethod(obj, methodId);

    //Return the facet count (an int)
    return result;
}

extern "C"
{

JNIEXPORT jstring JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_getMessageFromNative(JNIEnv *env, jobject callingObject)
{
    return env->NewStringUTF("Native code rules!");
}

JNIEXPORT jfloat JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_getMemberFieldFromNative(JNIEnv *env, jobject callingObject, jobject obj) //obj is the MeshData java object passed
{
    float result = 0.0f;

    //Get the passed object's class
    jclass cls = env->GetObjectClass(obj);

    // get field [F = Array of float
    jfieldID fieldId = env->GetFieldID(cls, "VertexCoords", "[F");

    // Get the object field, returns JObject (because it’s an Array)
    jobject objArray = env->GetObjectField (obj, fieldId);

    // Cast it to a jfloatarray
    jfloatArray* fArray = reinterpret_cast<jfloatArray*>(&objArray);

    jsize len = env->GetArrayLength(*fArray);

    // Get the elements
    float* data = env->GetFloatArrayElements(*fArray, 0);

    for(int i=0; i<len; ++i)
    {
        result += data[i];
    }

    // Don't forget to release it
    env->ReleaseFloatArrayElements(*fArray, data, 0);

    return result;
}

JNIEXPORT jint JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_invokeMemberFuncFromNative(JNIEnv *env, jobject callingObject, jobject obj)
{
    jclass cls = env->GetObjectClass(obj);
    jmethodID methodId = env->GetMethodID(cls, "getFacetCount", "()I");
    int result = env->CallIntMethod(obj, methodId);

    //Return the facet count (an int)
    return result;
}

JNIEXPORT jobject JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_createObjectFromNative(JNIEnv *env, jobject callingObject, jint param)
{
    jclass cls = env->FindClass("com/example/nsbr/hellojniapp/MeshData");
    jmethodID methodId = env->GetMethodID(cls, "<init>", "(I)V");
    jobject obj = env->NewObject(cls, methodId, param);

    return obj;
}

JNIEXPORT jint JNICALL
Java_com_example_nsbr_hellojniapp_MainActivity_processObjectArrayFromNative(JNIEnv *env, jobject callingObject, jobjectArray objArray)
{
    int resultSum = 0;

    int len = env->GetArrayLength(objArray);

    //Get all the objects in the array
    for(int i=0; i<len; ++i)
    {
        jobject obj = (jobject) env->GetObjectArrayElement(objArray, i);

        resultSum += getFacetCount(env, obj);
    }

    return resultSum;
}

}








