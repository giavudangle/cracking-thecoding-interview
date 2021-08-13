#include <bits/stdc++.h>

const int MN = 1000111;

int pi[MN];

int main(){

    char s[MN]= {'A','B','D','A','B','D'};
    char t[MN]= {'A','B','C','D','A','B','D','A','B','D','E','A','B','D'};



    int j;
    j = pi[1] = 0;
    for (int i = 2; s[i]; ++i) {
        while (j > 0 && s[j + 1] != s[i]) j = pi[j];
        if (s[j + 1] == s[i]) ++j;
        pi[i] = j;
    }

    j = 0;
    for (int i = 1; t[i]; ++i) {
        while (j > 0 && s[j + 1] != t[i]) j = pi[j];
        if (s[j + 1] == t[i]) ++j;

        if (s[j + 1] == 0) { // Het xau s
            std::cout << "Matching at index : " << i - j + 1 << std::endl;
            j = pi[j];
        }
    }
    return 0;
}