#include <stdio.h>
#include <windows.h> // ��� ��������� ����� �������
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    int day = 0, month = 0, year = 0;
    int sum = 0, arcana = 0;
    int uspeh = 0; // ���������� ��� �������� ������������ �����

    // ���� �������
    system("color 71");
    HANDLE a;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(a, (1 << 4) + 4);


    // ����
    while (uspeh != 1 || day < 1 || day > 31) {
        printf("������� ���� �������� (����� �� 1 �� 31): ");
        uspeh = scanf_s("%d", &day);
        if (uspeh != 1 || day < 1 || day > 31) {
            printf("������: ������� ���������� ����.\n\n");
            while (getchar() != '\n'); // ������� ������
        }
    }

    // �����
    uspeh = 0; // ���������� ���������� ��� ���������� �����
    while (uspeh != 1 || month < 1 || month > 12) {
        printf("������� ����� �������� (����� �� 1 �� 12): ");
        uspeh = scanf_s("%d", &month);
        if (uspeh != 1 || month < 1 || month > 12) {
            printf("������: ������� ���������� �����.\n\n");
            while (getchar() != '\n');
        }
    }

    // ���
    uspeh = 0; // ���������� ���������� ��� ���������� �����
    while (uspeh != 1 || year < 1 || year > 10000) {
        printf("������� ��� �������� (����� �� 1800 �� 2100): ");
        uspeh = scanf_s("%d", &year);
        if (uspeh != 1 || year < 1 || year > 10000) {
            printf("������: ������� ���������� ���.\n\n");
            while (getchar() != '\n');
        }
    }

    sum = day + month + year;

    // ��������� ����� ���������� �� ��������� ����� �� 1 �� 22
    while (sum > 22) {
        int tSum = 0;
        while (sum > 0) {
            tSum += sum % 10;
            sum /= 10;
        }
        sum = tSum;
    }

    // ���������� ����� = ������ �����
    arcana = sum;

    // ������ � ���������� �������
    const char* result[] = {
        "���",           // 0
        "���",           // 1
        "�����",         // 2
        "�����������",   // 3
        "���������",     // 4
        "��������",      // 5
        "����������",    // 6
        "���������",     // 7
        "��������������",// 8
        "���������",     // 9
        "������ �������",// 10
        "����",          // 11
        "����������",    // 12
        "������",        // 13
        "�����������",   // 14
        "������",        // 15
        "�����",         // 16
        "������",        // 17
        "����",          // 18
        "������",        // 19
        "���",           // 20
        "���"            // 21
    };

    // ������� �������� ������
    printf("��� ������ �����: %s\n", result[arcana]);

    return 0;
}
