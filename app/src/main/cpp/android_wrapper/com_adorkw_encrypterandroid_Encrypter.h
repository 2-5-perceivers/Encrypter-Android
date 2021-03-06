/* DO NOT EDIT THIS FILE - it is machine generated */

#include <jni.h>
/* Header for class com_adorkw_encrypterandroid_Encrypter */

#ifndef _Included_com_adorkw_encrypterandroid_Encrypter
#define _Included_com_adorkw_encrypterandroid_Encrypter
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    nativeCreateObject
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_adorkw_encrypterandroid_Encrypter_nativeCreateObject
  (JNIEnv *, jobject, jint keyLen);

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    encrypt
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_encrypt
  (JNIEnv* env, jobject, jlong nativeObjectHandle, jstring text, jstring key);

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    decrypt
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_decrypt
  (JNIEnv* env, jobject, jlong nativeObjectHandle, jstring text, jstring key);

#ifdef __cplusplus
}
#endif
#endif
