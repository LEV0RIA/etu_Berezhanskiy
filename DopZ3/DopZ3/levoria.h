#ifndef LEVORIA_H
#define LEVORIA_H

#include <stdio.h>

#define N 1024  // ������ ������ ��� ������ ������ �� info.txt

// ������� ������ ���� � ����
void record(FILE* log, int day, int month, int year, int success);

// ������� ������ ���������� �� ����� �� �����
void read(FILE* info, const char* arcanaName);

#endif  // LEVORIA_H
