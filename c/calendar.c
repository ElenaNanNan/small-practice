//
//  main.c
//  calendar
//
//  Created by zhuelena on 17/3/24.
//  Copyright © 2017 zhuelena. All rights reserved.
//

#include <stdio.h>


int calculate (int yearbase, int year, int month, int * dayofmonth) {
    int diff = 0;
    if (yearbase <= year) {  // date is after or on 2017
        while (yearbase < year) {
            diff += 365;
            if (yearbase % 400 == 0 || (yearbase % 4 == 0 && yearbase % 100 != 0)) {
                diff++;
            }
            yearbase++;
        }
        for (int i = 0; i < month - 1; i++) {
            diff += dayofmonth[i];
        }
        if (yearbase % 400 == 0 || (yearbase % 4 == 0 && yearbase % 100 != 0)) {
            if (month > 2) diff++;
        }
        return diff % 7;
    }
    else {  // year< yearbase
        yearbase--;
        while (year < yearbase) {
            diff += 365;
            if (yearbase % 400 == 0 || (yearbase % 4 == 0 && yearbase % 100 != 0)) {
                diff++;
            }
            yearbase--;
        }
        for (int j = 11; j >= month-1; j--) {
            diff += dayofmonth[j];
        }
        if (yearbase % 400 == 0 || (yearbase % 4 == 0 && yearbase % 100 != 0)) {
            if (month <= 2) diff++;
        }
        if (diff % 7 == 0) {
            return 0;
        }
        return 7 - (diff % 7);
    }
}

void print(int xxday, int year, int month, int numofday) {
    printf("Here is the calender of %d\\%d\n", year, month);
    for (int i = 0; i < 4*7; i++) {
        printf("*");
    }
    printf("\n");
    printf("SUN MON TUE WED THU FRI SAT\n");
    for (int i = 0; i < xxday; i++) {
        printf("    ");
    }
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        if (month == 2) {
            numofday = 29;
        }
    }
    for (int i = 1; i <= 9; i++) {
        printf("  %d ", i);
        xxday++;
        if (xxday == 7) {
            printf("\n");
            xxday = 0;
        }
    }
    for (int i = 10; i <= numofday; i++) {
        printf(" %d ", i);
        xxday++;
        if (xxday == 7) {
            printf("\n");
            xxday = 0;
        }
    }
    for (int i = xxday; i < 7; i++) {
        printf("    ");
    }
    printf("\n");
    for (int i = 0; i < 4*7; i++) {
        printf("*");
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    printf("Enter a year and a month in form of xxxx/xx");
    int year, month, xxday;  // 0< xxday <6 represent from sunday to saterday
    char c;
    scanf("%d %c %d", &year, &c, &month);
    if (month > 12 || month < 1) {
        printf("ERROR: no such month"); return 0;
    }
    int dayofmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int yearbase = 2017; // since 2017/1/1 is sunday
    xxday = calculate(yearbase, year, month, dayofmonth);
    print(xxday, year, month, dayofmonth[month-1]);
    return 0;
}
