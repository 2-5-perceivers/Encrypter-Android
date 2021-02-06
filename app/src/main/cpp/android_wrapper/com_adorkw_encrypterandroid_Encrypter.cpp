#include "com_adorkw_encrypterandroid_Encrypter.h"
#include "Encrypter.h"
#include "baseChanger/baseChanger.h"

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
  (JNIEnv * env, jobject, jint keyLen) {
    jlong pointer;
    try {
        pointer = (jlong) new Encrypter(keyLen);
    } catch (std::runtime_error& e) {
        pointer = (jlong) 0;
    }
    return pointer;
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    encrypt
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_encrypt
  (JNIEnv* env, jobject, jlong nativeObjectHandle, jstring text, jstring key)
{
    auto* encrypterInstance = (Encrypter*)nativeObjectHandle;
    std::string output;
    std::string s_key(jstring2string(env, key));
    std::string  s_input(jstring2string(env, text));
    auto* jniKey = (unsigned char *) s_key.c_str();
    auto* input = (unsigned char *) s_input.c_str();
    output = reinterpret_cast<char*>(encrypterInstance->encrypt(input, strlen(reinterpret_cast<const char *>(input)) * sizeof(unsigned char), jniKey));
    return env->NewStringUTF(toHex(output).c_str());
}

/*
 * Class:     com_adorkw_encrypterandroid_Encrypter
 * Method:    decrypt
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
extern "C" JNIEXPORT jstring JNICALL Java_com_adorkw_encrypterandroid_Encrypter_decrypt
(JNIEnv* env, jobject, jlong nativeObjectHandle, jstring text, jstring key)
{
    auto* encrypterInstance = (Encrypter*)nativeObjectHandle;
    std::string output, reason;
    std::string s_key(jstring2string(env, key));
    std::string s_input(jstring2string(env, text));
    bool failed = false;
    try {
        s_input = fromHex(s_input);
    } catch (std::invalid_argument& e) {
        reason = e.what();
        failed = true;
    }
    auto* jniKey = (unsigned char *) s_key.c_str();
    auto* input = (unsigned char *) s_input.c_str();
    try{
        output = reinterpret_cast<char*>(encrypterInstance->decrypt(input, s_input.length(), jniKey));
    } catch (...) {
        output = "Decryption failed";
    }
    if (failed){
        return env->NewStringUTF(reason.c_str());
    } else {
        return env->NewStringUTF(output.c_str());
    }
}


