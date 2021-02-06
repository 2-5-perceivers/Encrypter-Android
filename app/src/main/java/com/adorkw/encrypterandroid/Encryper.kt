package com.adorkw.encrypterandroid


class Encrypter(keyLen: Int = 256) {

    companion object {
        init {
            System.loadLibrary("encrypterlib_jni")
        }
    }

    fun encrypt(text: String, key: String): String {
        return encrypt(nativeObjectHandle, text, key)
    }

    fun decrypt(text: String, key: String): String {
        return decrypt(nativeObjectHandle, text, key)
    }

    private val nativeObjectHandle: Long
    private external fun nativeCreateObject(keyLen: Int): Long
    private external fun encrypt(nativeObjectHandle: Long, text: String, key: String): String
    private external fun decrypt(nativeObjectHandle: Long, text: String, key: String): String

    init {
        nativeObjectHandle = nativeCreateObject(keyLen)
        if (nativeObjectHandle == 0.toLong()){
            throw error("creating object failed")
        }

    }
}