# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("encrypterandroid")

#Build native library
set(CMAKE_CXX_STANDARD 17)

add_library(
        encrypterlib
        SHARED
        encrypter/Encrypter.cpp
        encrypter/textTransform/text_transform.cpp
        encrypter/baseChanger/baseChanger.cpp
)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        encrypterlib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )


include_directories(${CMAKE_SOURCE_DIR}/encrypter)

add_library(
        encrypterlib_jni
        SHARED
        android_wrapper/com_adorkw_encrypterandroid_Encrypter.cpp
        android_wrapper/com_adorkw_encrypterandroid_Encrypter_Companion.cpp
)

target_link_libraries(
        encrypterlib_jni
        encrypterlib
)