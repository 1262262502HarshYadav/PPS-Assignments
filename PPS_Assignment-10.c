#include <stdio.h>

// Returns 1 if leap year, 0 otherwise
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Returns the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
// Uses Sakamoto's algorithm
int getStartDay(int year, int month) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) {
        year -= 1;
    }
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + 1) % 7;
}

int main() {
    int year;
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid year.\n");
        return 1;
    }

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    int currentDay = getStartDay(year, 1);

    for (int m = 0; m < 12; m++) {
        printf("\n  ------------ %s %d ------------\n", months[m], year);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces for the first week
        for (int space = 0; space < currentDay; space++) {
            printf("     ");
        }

        // Print all days of the current month
        for (int day = 1; day <= daysInMonth[m]; day++) {
            printf("%5d", day);