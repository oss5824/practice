#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<regex>
using namespace std;
int main()
{
	char s[151]; scanf("%s", s);
	regex reg("(100+1+|01)+");
	if (regex_match(s, reg))printf("SUBMARINE");
	else printf("NOISE");
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);