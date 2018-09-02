//
//  ULog.h
//  ULog
//
//  Created by QiJunXian on 2018/9/1.
//  Copyright © 2018年 QiJunXian. All rights reserved.
//

#ifndef ULog_h
#define ULog_h

const char* FilePath = "file.txt";
const char* ErrorPath = "err.txt";

void LogDebug(unsigned int UserID, const char* format, ...);
void LogErr(unsigned int UserID, int RetCode, const char* format, ...);

#define LOGDEBUG LogDebug
#define LOGERR LogErr
#endif /* ULog_h */
