
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>


using namespace std;

const int MN = 1000111;

char s[MN], t[MN];
int nextt[MN];

int main() {
    scanf("%s\n", &t[1]);
    scanf("%s\n", &s[1]);

    int j;
    j = nextt[1] = 0;
    for (int i = 2; s[i]; ++i) {
        while (j > 0 && s[j + 1] != s[i]) j = nextt[j];
        if (s[j + 1] == s[i]) ++j;
        nextt[i] = j;
    }

    j = 0;
    for (int i = 1; t[i]; ++i) {
        while (j > 0 && s[j + 1] != t[i]) j = nextt[j];
        if (s[j + 1] == t[i]) ++j;

        if (s[j + 1] == 0) { // Het xau s
            printf("%d ", i - j + 1);
            j = nextt[j];
        }
    }
    puts("");
    return 0;
}