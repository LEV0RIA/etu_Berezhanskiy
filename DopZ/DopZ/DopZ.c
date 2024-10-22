#include <stdio.h>
#include <windows.h> // Для изменения цвета консоли
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    int day = 0, month = 0, year = 0;
    int sum = 0, arcana = 0;
    int uspeh = 0; // Переменная для проверки корректности ввода

    // Цвет консоли
    system("color 71");
    HANDLE a;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(a, (1 << 4) + 4);


    // День
    while (uspeh != 1 || day < 1 || day > 31) {
        printf("Введите день рождения (число от 1 до 31): ");
        uspeh = scanf_s("%d", &day);
        if (uspeh != 1 || day < 1 || day > 31) {
            printf("Ошибка: Введите корректный день.\n\n");
            while (getchar() != '\n'); // Очистка буфера
        }
    }

    // Месяц
    uspeh = 0; // Сбрасываем переменную для следующего ввода
    while (uspeh != 1 || month < 1 || month > 12) {
        printf("Введите месяц рождения (число от 1 до 12): ");
        uspeh = scanf_s("%d", &month);
        if (uspeh != 1 || month < 1 || month > 12) {
            printf("Ошибка: Введите корректный месяц.\n\n");
            while (getchar() != '\n');
        }
    }

    // Год
    uspeh = 0; // Сбрасываем переменную для следующего ввода
    while (uspeh != 1 || year < 1 || year > 10000) {
        printf("Введите год рождения (число от 1800 до 2100): ");
        uspeh = scanf_s("%d", &year);
        if (uspeh != 1 || year < 1 || year > 10000) {
            printf("Ошибка: Введите корректный год.\n\n");
            while (getchar() != '\n');
        }
    }

    sum = day + month + year;

    // Суммируем цифры результата до получения числа от 1 до 22
    while (sum > 22) {
        int tSum = 0;
        while (sum > 0) {
            tSum += sum % 10;
            sum /= 10;
        }
        sum = tSum;
    }

    // Полученное число = высший аркан
    arcana = sum;

    // Массив с названиями арканов
    const char* result[] = {
        "Шут",           // 0
        "Маг",           // 1
        "Жрица",         // 2
        "Императрица",   // 3
        "Император",     // 4
        "Иерофант",      // 5
        "Влюбленные",    // 6
        "Колесница",     // 7
        "Справедливость",// 8
        "Отшельник",     // 9
        "Колесо Фортуны",// 10
        "Сила",          // 11
        "Повешенный",    // 12
        "Смерть",        // 13
        "Умеренность",   // 14
        "Дьявол",        // 15
        "Башня",         // 16
        "Звезда",        // 17
        "Луна",          // 18
        "Солнце",        // 19
        "Суд",           // 20
        "Мир"            // 21
    };

    // Выводим название аркана
    printf("Ваш высший аркан: %s\n", result[arcana]);

    return 0;
}
