#ifndef _fileutil_h
#define _fileutil_h

extern int file_exists(const char *p);
extern char* get_exe_path(void);
extern char* make_path(const char* base, const char* name);

#endif
