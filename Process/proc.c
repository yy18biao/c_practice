#include"proc.h"

void ProncessOn(){
    int count = 0;
    char bar[101]={'\0'};
    char bar2[3]={'/','\\','|'};
    while(count <= 100){
        printf("[%-100s][%3d%%][%c]\r", bar, count, bar2[count % 3]);
        fflush(stdout);
        bar[count++] = '#';
        //sleep(1);
        usleep(50000);
    }

    printf("\n");
}

