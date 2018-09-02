//
//  ULog.cpp
//  ULog
//
//  Created by QiJunXian on 2018/9/1.
//  Copyright © 2018年 QiJunXian. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <cstring>

extern const char* FilePath;
extern const char* ErrorPath;

void LogDebug(unsigned int ID, const char* format, ...)
{
    FILE * fp;
    fp = fopen (FilePath, "a+");
    
    time_t t = time(0);
    char tmp[22];
    strftime(tmp, sizeof(tmp), "[%Y/%m/%d %X] ",localtime(&t));
    
    if(fp == NULL)
        printf("create fp fail");
    
    fprintf(fp, tmp);
    fprintf(fp, "ID: %d, ", ID);
    
    va_list args;
    va_start(args, format);
    vfprintf(fp, format, args);
    va_end(args);
    
    fclose(fp);
}

void LogErr(unsigned int ID, int RetCode, const char* format, ...)
{
    FILE * fp;
    fp = fopen (ErrorPath, "a+");
    
    if(fp == NULL)
        printf("create fp fail");
    
    time_t t = time(0);
    char tmp[22];
    strftime(tmp, sizeof(tmp), "[%Y/%m/%d %X] ",localtime(&t));
    
    fprintf(fp, tmp);
    fprintf(fp, "ID: %d, Retcode: %d, ", ID, RetCode);
    
    va_list args;
    va_start(args, format);
    vfprintf(fp, format, args);
    va_end(args);
    fclose(fp);
}
