#include "com_adorkw_encrypterandroid_Encrypter.h"
#include "Encrypter.h"

#include <jni.h>
#include <string>

std::string jstring2string(JNIEnv *env, jstring jStr) {
    if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, nullptr);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    nativeCreateObject
 * Signature: (Ljava/lang/String;)J
 */
extern "C" JNIEXPORT jlong JNICALL Java_com_adorkw_encrypterandroid_Encrypter_nativeCreateObject
  (JNIEnv * env, jobject, jstring encryptionKey)
{
    return (jlong) new Encrypter(jstring2string(env, encryptionKey));
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    encrypt
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_encrypt
  (JNIEnv* env, jobject, jlong nativeObjectHandle, jstring s)
{
    auto* encrypterInstance = (Encrypter*)nativeObjectHandle;
    return env->NewStringUTF(encrypterInstance->encrypt(jstring2string(env, s)).c_str());
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    decrypt
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_decrypt
(JNIEnv* env, jobject, jlong nativeObjectHandle, jstring s)
{
    auto* encrypterInstance = (Encrypter*)nativeObjectHandle;
    return env->NewStringUTF(encrypterInstance->decrypt(jstring2string(env, s)).c_str());
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    getKey
 * Signature: (J)Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_getKey
  (JNIEnv* env, jobject, jlong nativeObjectHandle)
{
    auto* encrypterInstance = (Encrypter*)nativeObjectHandle;
    return env->NewStringUTF(encrypterInstance->getkey().c_str());
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    setKey
 * Signature: (JLjava/lang/String;)Ljava/lang/Void;
 */
extern "C" JNIEXPORT jobject JNICALL Java_com_adorkw_encrypterandroid_Encrypter_setKey
  (JNIEnv* env, jobject, jlong nativeObjectHandle, jstring s)
{
    auto* encrypterInstance = (Encrypter*)nativeObjectHandle;
    encrypterInstance->setkey(jstring2string(env, s));
}

