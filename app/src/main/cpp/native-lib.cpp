#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_adorkw_encrypterandroid_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from caca";
    return env->NewStringUTF(hello.c_str());
}