#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};
int getDaysInMonth(struct date);
struct date getNextWeek(struct date);
int main(void) {
    struct date input; // Date entered by user
    struct date output; // 7 days after the date entered by user

    printf("Enter date (mm/dd/yyyy or mm-dd-yyyy): ");
    scanf("%d%*[/-]%d%*[/-]%d", &input.month, &input.day, &input.year);

    // Call function to calculate the date 7 days later
    output = getNextWeek(input);

    printf("7 days from date: %02d/%02d/%d.\n", output.month, output.day, output.year);

    return 0;
}
int getDaysInMonth(struct date dt) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if (dt.year % 400 == 0 || (dt.year % 100 != 0 && dt.year % 4 == 0)) {
        daysInMonth[1] = 29;
    }

    return daysInMonth[dt.month - 1];
}
struct date getNextWeek(struct date d) {
    struct date result;
    int daysInMonth = getDaysInMonth(d);

    if (d.day + 7 <= daysInMonth) {
        result.day = d.day + 7;
        result.month = d.month;
        result.year = d.year;
    } else {
        result.day = (d.day + 7) - daysInMonth;
        if (d.month == 12) {
            result.month = 1;
            result.year = d.year + 1;
        } else {
            result.month = d.month + 1;
            result.year = d.year;
        }
    }

    return result;
}
