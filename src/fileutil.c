
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <string.h>
#ifndef MAX_PATH
#define MAX_PATH 260
#endif
#ifndef PATH_MAX
#define PATH_MAX MAX_PATH
#endif
int file_exists(const char *p)
{
    unsigned long attr = GetFileAttributes(p);
    if (attr == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}
char* get_exe_path(void)
{
    static char s_result[2048] = {0};

    if (!s_result[0]) {
        char* p;
        int  len;
        char exe_full_path[PATH_MAX];

        len = GetModuleFileNameA(NULL, exe_full_path, PATH_MAX);
        if (len > 0) {
            strncpy(s_result, exe_full_path, 2040);
            p = strrchr(s_result, '\\');
            if (p) *p = 0;
            for (char *s = s_result; *s; ++s) {
                if (*s == '\\') *s = '/';
            }
        }
    }

    return s_result;
}
char* make_path(const char* base, const char* name)
{
    static char buf[4096] = {0};
    strcpy(buf, base);
    strcat(buf, "/");
    strcat(buf, name);
    return buf;
}
#else
#include <linux/limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
int file_exists(const char *p)
{
    struct stat st;
    return stat(p, &st) == 0 ? 1 : 0;
}
char* get_exe_path(void)
{
    static char s_result[2048] = {0};

    if (!s_result[0]) {
        char* p;
        char exe_full_path[PATH_MAX];
        ssize_t s = readlink("/proc/self/exe", exe_full_path, PATH_MAX);
        if (s > 0) {
            strncpy(s_result, exe_full_path, 2040);
            p = strrchr(s_result, '/');
            if (p) *p = 0;
        }
    }

    return s_result;
}
char* make_path(const char* base, const char* name)
{
    static char buf[4096] = {0};
    strcpy(buf, base);
    strcat(buf, "/");
    strcat(buf, name);
    return buf;
}
#endif
