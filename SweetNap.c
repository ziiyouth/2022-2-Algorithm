#include<stdio.h>
#include <string.h>  

// Up to 100 schedules
#define MAX_Schedule 100

// Start and end struct settings (int)
typedef struct {
    int startTime;
    int endTime;
} Schedule;

// Convert char to int
// How long has it been since 10
int char2int(char* hh, char* mm) {
    return (hh[1] - '0') * 60 + (mm[0] - '0') * 10 + (mm[1] - '0');
}


void main() {
    char str[255];
    Schedule schedule[MAX_Schedule + 2];
    int TotalNum, min = 0, DayNum = 0;
    int MaxTime = 0, StartHM = 0;
    
    // the number of attempts received
    while (scanf_s("%d", &TotalNum) == 1) {
        gets(str);
        Schedule temp;
        DayNum++;

        // Initialize struct first and end values
        schedule[0].startTime = 0;
        schedule[0].endTime = 0;
        schedule[TotalNum + 1].startTime = 8 * 60;
        schedule[TotalNum + 1].endTime = 8 * 60;


        // Cut the string, divide hh/mm, and put it in the struct
        for (int i = 1; i <= TotalNum; i++) {
            gets(str);
            schedule[i].startTime = char2int(str, str + 3);
            schedule[i].endTime = char2int(str + 6, str + 9);

        }
    
        // Sort by time
        // Compare the size of the start value
        for (int i = 1; i < TotalNum; i++) {
            min = i;
            for (int j = i; j <= TotalNum; j++)
                if (schedule[j].startTime < schedule[min].startTime)
                    min = j;
            temp = schedule[i];
            schedule[i] = schedule[min];
            schedule[min] = temp;
        }

        // Getting the Longest Naps
        MaxTime = schedule[1].startTime - schedule[0].endTime;
        for (int i = 1; i <= TotalNum; i++) {
            if (schedule[i + 1].startTime - schedule[i].endTime > MaxTime) {
                MaxTime = schedule[i + 1].startTime - schedule[i].endTime;
                StartHM = i;
            }

        }

        printf("Day #%d: the longest nap starts at ", DayNum);
        printf("1%d:%02d and will last for ",
            schedule[StartHM].endTime / 60,
            schedule[StartHM].endTime % 60);

        if (MaxTime >= 60)
            printf("%d hours and %d minutes.\n", MaxTime / 60, MaxTime % 60);
        else
            printf("%d minutes.\n", MaxTime);
    }
}