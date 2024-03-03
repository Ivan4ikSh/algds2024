#include <stdio.h>

#include "framework.h"
#include "test.h"

void main() {
	TEST(19, "tests_folder/test1.txt");
	TEST(0, "tests_folder/test2.txt");
	TEST(20, "tests_folder/test3.txt");
	TEST(0, "tests_folder/test4.txt");
	TEST(16, "tests_folder/test5.txt");
	//printf("total sum: %d", Finder(data));
}

/*
������ ����� � � ��� ������� b[1..n] � c[1..n].
c[i] � ��������� i-�� ��������, b[i] � ��� ���.

��������������, ��� 1<b[i]<=A.
����� ��������� I, ���������� ������������� ��������� {1,...,n}, �����, ��� SUM_i_b <= �, a SUM_i_c �������� ������������.

���������:
��������� ����� F[k,y] �������� ���������� ��������� ��������� ���������
� �������� �� �������� k, ��������� ��� ������� �� ��������� y.

7 5
2 4 2 3 2
1 2 3 4 5
*/