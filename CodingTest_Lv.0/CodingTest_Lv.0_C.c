// 1

// "aya", "ye", "woo", "ma" 네 가지 발음을 최대 한 번씩 사용해 이어붙인 발음
// 문자열 배열 babbling이 매개변수로 주어질 때, 발음할 수 있는 단어 개수 반환하는 함수 완성

// 제한사항
// 1 <= babbling 길이 <= 100
// 1 <= babbling[i] 길이 <= 15
// 문자열은 소문자로만 이루어져 있음

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

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

// 등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 마지막 원소 다음으로 올 숫자를 반환하도록 함수 완성

// 제한사항
// 2 < common 길이 < 1000
// -1000 < common 원소 < 2000
// 등비수열인 경우 공비는 0이 아닌 정수

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int d = 0, r = 0;

    // 등차수열 or 등비수열 판단
    // 등차수열인 경우,
    if ((common[2] - common[1]) == (common[1] - common[0])) {
        d = common[1] - common[0];
        answer = common[common_len - 1] + d;
    }
    // 등비수열인 경우,
    else {
        r = common[1] / common[0];
        answer = common[common_len - 1] * r;
    }
    return answer;
}
*/

// 3

// 두 정수 num과 total이 주어짐. 연속된 수 num개를 더한 값이 total이 될 때, 정수 배열을 오름차순으로 담아 반환하는 함수 완성

// 제한사항
// 1 <= num <= 100
// 0 <= total <= 1000
// num개의 연속된 수를 더하여 total이 될 수 없는 케이스는 없음

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num, int total) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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

// 문자열 A와 B가 매개변수로 주어질 때, A를 밀어서 B가 될 수 있다면 밀어야 하는 최소 횟수를 반환하고 밀어서 B가 될 수 없으면 -1을 반환하도록 함수 완성

// 제한사항
// 0 < A의 길이 = B의 길이 < 100
// A, B는 알파벳 소문자로 이루어져 있음

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
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

// 문자열 my_str과 n이 매개변수로 주어질 때, my_str을 길이 n씩 잘라서 저장한 배열을 반환하도록 함수를 완성

// 제한사항
// 1 <= my_str 길이 <= 100
// 1<= n <= my_str 길이
// my_str은 알파벳 소문자, 대문자, 숫자로 이루어져 있음

/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_str, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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