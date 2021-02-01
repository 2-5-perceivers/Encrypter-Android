package com.adorkw.encrypterandroid


class Encrypter(encryptionKey: String = "default") {

    companion object {
        init {
            System.loadLibrary("encrypterlib_jni")
        }
        external fun generateRandomKey(keyLength: Int): String
    }

    fun encrypt(s: String): String {
        return encrypt(nativeObjectHandle, s)
    }

    fun decrypt(s: String): String {
        return decrypt(nativeObjectHandle, s)
    }

    fun getKey(): String{
        return getKey(nativeObjectHandle)
    }

    fun setKey(key: String){
        setKey(nativeObjectHandle, key)
    }

    private val nativeObjectHandle: Long
    private external fun nativeCreateObject(encryptionKey: String): Long
    private external fun encrypt(nativeObjectHandle: Long, s: String): String
    private external fun decrypt(nativeObjectHandle: Long, s: String): String
    private external fun getKey(nativeObjectHandle: Long): String
    private external fun setKey(nativeObjectHandle: Long, key: String): Void

    init {
        nativeObjectHandle = nativeCreateObject(encryptionKey)
    }
}