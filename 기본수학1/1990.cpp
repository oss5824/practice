#pragma warning(disable:4996)
#include <stdio.h>
#include <cstring>
int a, b;
bool arr[10000001];
int main()
{
    scanf("%d %d", &a, &b);
    if (b >= 10000000)b = 10000000;
    for (int i = 2; i * i <= b; i++) {
        if (arr[i])continue;
        for (int j = i + i; j <= b; j += i)arr[j] = true;
    }
    for (int i = a; i <= b; i++)
        if (!arr[i]) {
            char str[11];
            int len = sprintf(str, "%d", i), s = 0, e = len - 1;
            bool check = true;
            while (s < e) {
                if (str[s] == str[e]) { s++; e--; }
                else { check = false; break; }
            }
            if (check)printf("%d\n", i);
        }
    printf("-1");
}