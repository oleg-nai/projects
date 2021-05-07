#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
struct Month {
    char month_name[20];
    int num_of_month;
};

struct Day {
    char day_name[10];
};

int DayMonth(char* Mes) {
    int days = 0;
    for (int i = 0; i < strlen(Mes); i++) {
        days += (Mes[i] - 64);  // считаем номер буквы по таблице
        if (Mes[i] > 'J') days--; // в таблице Карпочич пропущена буква J, поэтому делаем проверку
    }
    return days;
}

int compare(const void* pa, const void* pb) { // нужно для qsort
    int num_b = ((struct Month*)pa)->num_of_month;
    int num_a = ((struct Month*)pb)->num_of_month;
    return num_b - num_a;
}

int num_of_all_days(struct Month* months, int num_of_months) {  // всего дней в году
    int sum = 0;
    for (int i = 0; i < num_of_months; i++) {
        sum += DayMonth(months[i].month_name);
    }
    return sum;
}

char* DayName(int num, int b, int num_of_days_per_week, struct Day* day) { // какой день соответствует числу k
    return day[(((num % num_of_days_per_week) + b - 1) % num_of_days_per_week) - 1].day_name;
}

void KDays(FILE* smile, struct Month* months, int k, int b, int num_of_months, int num_of_days_per_week, struct Day* day) {
    int this_day = k; // номер подозрительного дня в году
    int num = 0; // количество счастилвых дней
    for (int i = 0; i < num_of_months; i++) {
        if ((this_day - 1) % num_of_days_per_week == 0) { // если день счастливый, то печатаем всю инфу о нем
            fprintf(smile, "%d %s %s\n", k, months[i].month_name, DayName(this_day, b, num_of_days_per_week, day));
            num++;
        }
        this_day += DayMonth(months[i].month_name);
    }
    fprintf(smile, "Number of important days: %d\n", num);
    fprintf(smile, "Number of al days: %d\n", num_of_all_days(months, num_of_months));
}

int main(void) {

    FILE* month = fopen("Month.txt", "r");
    if (!month) {
        printf("File Month.txt is missing\n");
        return 1;
    }

    struct Month months[10]; // хранилище месяцев
    char str[80]; // промежуточная строка для хранения
    int num_months = 0; // количество месяцев
    char seps[] = " ,.{}!?-:;\n"; // разделители

    while (fgets(str, 80, month)) { // выделяем из файла строку
        char* pch = strtok(str, seps);
        while (pch) {
            strcpy(months[num_months].month_name, pch); // копируем название месяца
            months[num_months++].num_of_month = atoi(strtok(NULL, seps)); // копируем номер месяца
            pch = strtok(NULL, seps);
        }
    }

    fclose(month);

    int all_days = num_of_all_days(months, num_months); // количество всех дней в году

    qsort(months, num_months, sizeof(struct Month), compare); // сортируем месяца по порядку

    FILE* out = fopen("Out.txt", "w");

    if (!out) {
        printf("File Out.txt is missing\n");
        return 1;
    }

    for (int i = 0; i < num_months; i++) { // печатаем информацию в файл Out.txt
        fprintf(out, "%d - %s %d\n", months[i].num_of_month, months[i].month_name, DayMonth(months[i].month_name));
    }

    fclose(out);

    FILE* day = fopen("Day.txt", "r");
    if (!day) {
        printf("File Day.txt is missing\n");
        return 1;
    }
    struct Day days[9]; // хранилище дней
    fgets(str, 80, day);
    char* pch = strtok(str, seps);
    int num_of_days = atoi(pch); // количество дней в неделе
    int i = 0;
    fgets(str, 80, day);
    pch = strtok(str, seps);

    while (pch) {
        strcpy(days[i++].day_name, pch); // копируем имя дня
        pch = strtok(NULL, seps);
    }
    fclose(day);
    
    FILE* data = fopen("Data.txt", "r");
    if (!data) {
        printf("File Data.txt is missing\n");
        return 1;
    }

    fgets(str, 80, data);
    int b = atoi(strtok(str, seps));
    int k = atoi(strtok(NULL, seps));
    fclose(data);

    FILE* smile = fopen("Smile.txt", "w");
    if (!smile) {
        printf("File Smile.txt is missing\n");
        return 1;
    }

    KDays(smile, months, k, b, num_months, num_of_days, days); // печатаем в Smile.txt результаты

    return 0;
}