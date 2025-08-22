#include "process.h"
#include <string.h>
#include <unistd.h>

#define STYLE '='
#define NUM 101

// version2
void FlushProcess(double total, double current){  
    char buffer[NUM];
    memset(buffer, 0, sizeof(buffer));
    const char* label = "|/-\\";
    int len = strlen(label);
    static int cnt = 0;

    // 不需要自己循环，填充=
    int num = (int)(current*100/total);
    for(int i = 0; i < num; ++i){
        buffer[i] = STYLE;
    }
    double rate = current/total;
    cnt %= len;
    printf("[%-100s][%.1f%%][%c]\r", buffer, rate*100,label[cnt]);
    ++cnt;
    fflush(stdout);
}

// 无法使用
void process_v1(){
    char buffer[NUM];
    memset(buffer, 0, sizeof(buffer));
    const char* label = "|/-\\";
    int len = strlen(label);
    int cnt = 0;
    while(cnt <= 100){
        printf("[%-100s][%d%%][%c]\r", buffer, cnt, label[cnt%len]);
        buffer[cnt] = STYLE;
        ++cnt;
        fflush(stdout);
        usleep(50000);
    }
    printf("\n");
}
