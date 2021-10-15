#pragma warning(disable:4996)
#include<cstdio>
#include<string.h>
char str[102], stk[102];
int len, idx = -1;
int muldi(char c) { if (c == '*' || c == '/')return 1; else if (c == '+' || c == '-')return -1; else return 0; }
int main()
{
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i], ch;
        if ('A' <= c && c <= 'Z')printf("%c", c);
        else if (c == '(')stk[++idx] = '(';
        else if (c == ')') { while (stk[idx] != '(')printf("%c", stk[idx--]); idx--; }
        else {
            int c_val = muldi(c);
            if (c_val == -1) {
                while (idx >= 0 && (muldi(stk[idx]) != 0))printf("%c", stk[idx--]);
                stk[++idx] = str[i];
            }
            else if (c_val == 1) {
                while (idx >= 0 && (muldi(stk[idx]) == 1))printf("%c", stk[idx--]);
                stk[++idx] = str[i];
            }
        }
    }for (int i = idx; i >= 0; i--)printf("%c", stk[i]);
}