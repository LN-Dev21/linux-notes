#include "process.h"
#include <stdio.h>
#include <unistd.h>

typedef void (*callback_t)(double total, double current);

double total = 1023.0;
double speed = 1.0;

void DownLoad(callback_t cb){
    double current = 0;
    while(current <= total){
        cb(total, current);
        // 下载代码
        usleep(3000); // 充当下载数据
        current += speed;
    }
    printf("\n");
    printf("Download %.2lfMB Done!\n", current);
}

void UpLoad(callback_t cb){
    double current = 0;
    while(current <= total){
        cb(total, current);
        // 上传代码
        usleep(3000); // 充当上传数据
        current += speed;
    }
    printf("\n");
    printf("Upload %.2lfMB Done!\n", current);
}
int main(){
    DownLoad(FlushProcess);
    UpLoad(FlushProcess);
    return 0;
}
