// 1

// "aya", "ye", "woo", "ma" �� ���� ������ �ִ� �� ���� ����� �̾���� ����
// ���ڿ� �迭 babbling�� �Ű������� �־��� ��, ������ �� �ִ� �ܾ� ���� ��ȯ�ϴ� �Լ� �ϼ�

// ���ѻ���
// 1 <= babbling ���� <= 100
// 1 <= babbling[i] ���� <= 15
// ���ڿ��� �ҹ��ڷθ� �̷���� ����

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len�� �迭 babbling�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.

bool func2(const char* str, size_t len) {
    if (len == 2) {
        return (strcmp(str, "ye") == 0) || (strcmp(str, "ma") == 0);
    }
    else if (len == 3) {
        return (strcmp(str, "aya") == 0) || (strcmp(str, "woo") == 0);
    }
    return false;
}

bool func1(const char* str) {
    char s[4] = { 0, };
    char s2[4] = { 0, };
    int idx = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        s[idx++] = str[i];
        if (idx == 1) continue;
        if (func2(s, idx)) {
            if (strcmp(s2, s) == 0) return false;
            memcpy(s2, s, 4); idx = 0; s[2] = 0;
        }
        else if (idx == 3) return false;
    }
    if (idx != 0) return false;
    return true;
}

int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    for (int i = 0; i < babbling_len; i++) {
        if (func1(babbling[i])) answer++;
    }
    return answer;
}
*/

// 2

// �������� Ȥ�� ������ common�� �Ű������� �־��� ��, ������ ���� �������� �� ���ڸ� ��ȯ�ϵ��� �Լ� �ϼ�

// ���ѻ���
// 2 < common ���� < 1000
// -1000 < common ���� < 2000
// �������� ��� ����� 0�� �ƴ� ����

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len�� �迭 common�� �����Դϴ�.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int d = 0, r = 0;

    // �������� or ������ �Ǵ�
    // ���������� ���,
    if ((common[2] - common[1]) == (common[1] - common[0])) {
        d = common[1] - common[0];
        answer = common[common_len - 1] + d;
    }
    // �������� ���,
    else {
        r = common[1] / common[0];
        answer = common[common_len - 1] * r;
    }
    return answer;
}
*/

// 3

// �� ���� num�� total�� �־���. ���ӵ� �� num���� ���� ���� total�� �� ��, ���� �迭�� ������������ ��� ��ȯ�ϴ� �Լ� �ϼ�

// ���ѻ���
// 1 <= num <= 100
// 0 <= total <= 1000
// num���� ���ӵ� ���� ���Ͽ� total�� �� �� ���� ���̽��� ����

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num, int total) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(500);

    int mid = total / num;
    int cnt = (num - 1) / 2;
    int start = mid - cnt;

    for (int i = 0; i < num; i++)
    {
        answer[i] = start + i;
    }

    return answer;
}
*/

// 4

// ���ڿ� A�� B�� �Ű������� �־��� ��, A�� �о B�� �� �� �ִٸ� �о�� �ϴ� �ּ� Ƚ���� ��ȯ�ϰ� �о B�� �� �� ������ -1�� ��ȯ�ϵ��� �Լ� �ϼ�

// ���ѻ���
// 0 < A�� ���� = B�� ���� < 100
// A, B�� ���ĺ� �ҹ��ڷ� �̷���� ����

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(const char* A, const char* B) {
    int answer = -1;
    int len = strlen(A);
    char* temp1 = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            temp1[j] = A[(len - i + j) % len];

        if (strncmp(temp1, B, len) == 0)
        {
            answer = i;
            break;
        }
    }
    free(temp1);
    return answer;
}
*/

// 5

// ���ڿ� my_str�� n�� �Ű������� �־��� ��, my_str�� ���� n�� �߶� ������ �迭�� ��ȯ�ϵ��� �Լ��� �ϼ�

// ���ѻ���
// 1 <= my_str ���� <= 100
// 1<= n <= my_str ����
// my_str�� ���ĺ� �ҹ���, �빮��, ���ڷ� �̷���� ����

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char** solution(const char* my_str, int n) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int len = strlen(my_str);
    int size = len % n ? len / n + 1 : len / n;
    char** answer = (char**)malloc(sizeof(char*) * size);
    int count = 0;
    for (int i = 0; i < len; i += n)
    {
        char* str = (char*)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++)
            str[j] = my_str[i + j];
        str[n] = 0;
        answer[count++] = str;
    }
    return answer;
}
*/