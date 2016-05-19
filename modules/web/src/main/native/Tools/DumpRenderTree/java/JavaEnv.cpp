/*
 * Copyright (c) 2011, 2013, Oracle and/or its affiliates. All rights reserved.
 */
#include "config.h"

#include "JavaEnv.h"

JavaVM* jvm = 0;

JNIEnv* JNICALL DumpRenderTree_GetJavaEnv()
{
    void* env;
    jvm->GetEnv(&env, JNI_VERSION_1_2);
    return (JNIEnv*)env;
}

bool CheckAndClearException(JNIEnv* env)
{
    if (JNI_TRUE == env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return true;
    }
    return false;
}

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    jvm = vm;
    return JNI_VERSION_1_2;
}

JNIEXPORT void JNICALL JNI_OnUnLoad(JavaVM* vm, void* reserved)
{
    jvm = 0;
}

#ifdef __cplusplus
}
#endif
