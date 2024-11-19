#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <chrono>
#include "levoria.h"

int main() {
    using namespace std::chrono;// Упрощаем использование. Не надо писать префикс
    high_resolution_clock::time_point start;// Начальная точка
    high_resolution_clock::time_point end;// Конечная точка

    setlocale(LC_ALL, "");
    int menu_position = 1;
    int key = 0;
    bool timer_start = false;// Флаг. Начался подсчёт времени?

    while (1) {
        system("cls");
        printf("Выберите пункт меню:\n");

        if (menu_position == 1) {
            printf("--> 1. Ввести дату <--\n");
        }
        else {
            printf("    1. Ввести дату\n");
        }

        if (menu_position == 2) {
            printf("--> 2. Вывести log.txt <--\n");
        }
        else {
            printf("    2. Вывести log.txt\n");
        }

        if (menu_position == 3) {
            printf("--> 3. Вывести время работы программы <--\n");
        }
        else {
            printf("    3. Вывести время работы программы\n");
        }

        if (menu_position == 4) {
            printf("--> 4. Выход <--\n");
        }
        else {
            printf("    4. Выход\n");
        }

        key = _getch();

        if (key == 80) {
            menu_position++;
            if (menu_position > 4) menu_position = 1;
        }
        else if (key == 72) {
            menu_position--;
            if (menu_position < 1) menu_position = 4;
        }
        else if (key == 13) {
            system("cls");
            if (menu_position == 1) {
                int day = 0, month = 0, year = 0;
                int sum = 0, arcana = 0;
                int uspeh = 0;

                FILE* log;
                FILE* info;
                fopen_s(&log, "log.txt", "a+");
                fopen_s(&info, "info.txt", "r");

                while (uspeh != 1 || day < 1 || day > 31) {
                    printf("Введите день рождения (число от 1 до 31): ");
                    uspeh = scanf_s("%d", &day);
                    if (uspeh != 1 || day < 1 || day > 31) {
                        printf("Ошибка: Введите корректный день.\n\n");
                        while (getchar() != '\n');
                    }
                }

                uspeh = 0;
                while (uspeh != 1 || month < 1 || month > 12) {
                    printf("Введите месяц рождения (число от 1 до 12): ");
                    uspeh = scanf_s("%d", &month);
                    if (uspeh != 1 || month < 1 || month > 12) {
                        printf("Ошибка: Введите корректный месяц.\n\n");
                        while (getchar() != '\n');
                    }
                }

                uspeh = 0;
                while (uspeh != 1 || year < 1800 || year > 2100) {
                    printf("Введите год рождения (число от 1800 до 2100): ");
                    uspeh = scanf_s("%d", &year);
                    if (uspeh != 1 || year < 1800 || year > 2100) {
                        printf("Ошибка: Введите корректный год.\n\n");
                        while (getchar() != '\n');
                    }
                }

                if (!timer_start) {
                    start = high_resolution_clock::now();// Начальная точка отсчета
                    timer_start = true;// Таймер запущен
                }

                record(log, day, month, year, 1);

                sum = day + month + year;
                while (sum > 22) {
                    int tSum = 0;
                    while (sum > 0) {
                        tSum += sum % 10;
                        sum /= 10;
                    }
                    sum = tSum;
                }
                arcana = sum;

                const char* result[] = {
                    "Шут", "Маг", "Жрица", "Императрица", "Император", "Иерофант", "Влюбленные",
                    "Колесница", "Справедливость", "Отшельник", "Колесо Фортуны", "Сила",
                    "Повешенный", "Смерть", "Умеренность", "Дьявол", "Башня", "Звезда",
                    "Луна", "Солнце", "Суд", "Мир"
                };

                printf("\nВаш высший аркан: %s\n", result[arcana]);
                read(info, result[arcana]);
                _getch();

                fclose(log);
                fclose(info);
            }

            if (menu_position == 2) {
                FILE* log;
                fopen_s(&log, "log.txt", "r");

                char line[N];
                while (fgets(line, N, log)) {
                    printf("%s", line);
                }
                fclose(log);
                printf("\nНажмите любую клавишу для возврата в меню...");
                _getch();
            }

            if (menu_position == 3) {
                if (timer_start) {
                    end = high_resolution_clock::now();// Конечная точка времени
                    auto duration = duration_cast<milliseconds>(end - start);// Вычисление времени
                    printf("Время работы программы: %d миллисекунд\n", duration.count());
                }
                else {
                    printf("Время работы пока не отсчитывается. Введите дату для запуска отсчета.\n");
                }
                _getch();
            }

            if (menu_position == 4) {
                if (timer_start) {
                    end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - start);
                    printf("Итоговое время работы программы: %d миллисекунд\n", duration.count());
                }
                break;
            }
        }
    }
    return 0;
}
