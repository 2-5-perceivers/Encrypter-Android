#include "com_adorkw_encrypterandroid_Encrypter_Companion.h"
#include "Encrypter.h"

#include <jni.h>
/*
 * Class:     com_adorkw_encrypterandroid_Encrypter_Companion
 * Method:    generateRandomKey
 * Signature: (I)V
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_00024Companion_generateRandomKey
  (JNIEnv* env, jobject, jint s)
{
    return env->NewStringUTF(Encrypter::generateRandomKey((int)s).c_str());
}

