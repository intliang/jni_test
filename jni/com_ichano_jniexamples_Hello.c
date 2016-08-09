#include "com_ichano_jniexamples_Hello.h"
#include <android/log.h>

#define LOG_TAG    "ichano-jni" // 这个是自定义的LOG的标识  
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__) // 定义LOGD类型  
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__) // 定义LOGI类型  
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__) // 定义LOGW类型  
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__) // 定义LOGE类型  
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,__VA_ARGS__) // 定义LOGF类型

JNIEXPORT void JNICALL Java_com_ichano_jniexamples_Hello_sayHi
  (JNIEnv *env, jclass clazz, jstring who, jint times) {
  const char *name = (*env)->GetStringUTFChars(env, who, 0);
  if (name != 0) {
    jint i;
    for (i = 0; i < times; i++) {
		LOGI("Hello %s\n", name);
      //printf("Hello %s\n", name);
    }
    (*env)->ReleaseStringUTFChars(env, who, name);
  }
}

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  JNIEnv* env;
  //printf("on load\n");
  LOGI("on load\n");
  return JNI_VERSION_1_2;
}