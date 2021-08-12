#include <bits/stdc++.h>

const int MN = 1000111;

int nextt[MN];

int main(){

    char s[MN]= {'A','B','C'};
    char t[MN]= {'A','B','C','A','B','C'};



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
            std::cout << "Matching at indexes : " << i - j + 1 << std::endl;
            j = nextt[j];
        }
    }
    return 0;
}