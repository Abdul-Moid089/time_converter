#include <stdio.h>
#include <string.h>

int main() {
    char time[10];
    int hr, min, sec;
    int fr;

    printf("Select your time format [Type '12' for 12-hour format and '24' for 24-hour format]: ");
    scanf("%d", &fr);

    if (fr == 12) {
        printf("\nEnter time in given format [hh:mm:ssAM/PM]: ");
        scanf("%s", time);

        sscanf(time, "%d:%d:%d", &hr, &min, &sec);

        if (hr < 1 || hr > 12 || min < 0 || min > 59 || sec < 0 || sec > 59) {
            printf("Invalid time entered.\n");
            return 1;
        }

        if (time[8] == 'P' && hr != 12) {
            hr += 12;
        } else if (time[8] == 'A' && hr == 12) {
            hr = 0;
        }

        printf("\nTime in 24-hour format: %02d:%02d:%02d\n", hr, min, sec);
    } 
    else if (fr == 24) {
        printf("\nEnter time in given format [hh:mm:ss]: ");
        scanf("%d:%d:%d", &hr, &min, &sec);

        if (hr < 0 || hr > 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
            printf("Invalid time entered.\n");
            return 1;
        }

        if (hr == 0) {
            hr = 12;
            printf("\nTime in 12-hour format: %02d:%02d:%02dAM\n", hr, min, sec);
        } else if (hr == 12) {
            printf("\nTime in 12-hour format: %02d:%02d:%02dPM\n", hr, min, sec);
        } else if (hr > 12) {
            hr -= 12;
            printf("\nTime in 12-hour format: %02d:%02d:%02dPM\n", hr, min, sec);
        } else {
            printf("\nTime in 12-hour format: %02d:%02d:%02dAM\n", hr, min, sec);
        }
    } else {
        printf("Invalid format selected.\n");
    }

    return 0;
}

