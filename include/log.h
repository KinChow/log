/*
 * @Author: Zhou Zijian 
 * @Date: 2023-12-16 01:37:29 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2023-12-16 01:57:50
 */

#ifndef LOG_H
#define LOG_H

#include <cstdio>
#include <ctime>

char *GetTime()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime = *std::localtime(&now);
    return std::asctime(&localTime);
}

#ifndef PROJECT_NAME
#define PROJECT_NAME ""
#endif  // PROJECT_NAME

#ifndef LOGD
#define LOGD(format, ...)                                                                                     \
    printf("[%-24.24s] [DEBUG] [%s] [%-24.24s] [%-4d] [" format "]\n", GetTime(), PROJECT_NAME, __FUNCTION__, \
        __LINE__, ##__VA_ARGS__);                                                                             \
    fflush(stdout)
#endif  // LOGD

#ifndef LOGI
#define LOGI(format, ...)                                                                                    \
    printf("[%-24.24s] [INFO] [%s] [%-24.24s] [%-4d] [" format "]\n", GetTime(), PROJECT_NAME, __FUNCTION__, \
        __LINE__, ##__VA_ARGS__);                                                                            \
    fflush(stdout)
#endif  // LOGI

#ifndef LOGW
#define LOGW(format, ...)                                                                                    \
    printf("[%-24.24s] [WARN] [%s] [%-24.24s] [%-4d] [" format "]\n", GetTime(), PROJECT_NAME, __FUNCTION__, \
        __LINE__, ##__VA_ARGS__);                                                                            \
    fflush(stdout)
#endif  // LOGW

#ifndef LOGE
#define LOGE(format, ...)                                                                                     \
    printf("[%-24.24s] [ERROR] [%s] [%-24.24s] [%-4d] [" format "]\n", GetTime(), PROJECT_NAME, __FUNCTION__, \
        __LINE__, ##__VA_ARGS__);                                                                             \
    fflush(stdout)
#endif  // LOGE

#endif  // LOG_H