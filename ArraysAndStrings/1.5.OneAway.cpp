/* 1.5.OneWay : There are three types of edits can be performed on strings: 
insert a character, remove a character, replace a character.
Given two strings, write a function to check if they are one edit(or zero edits) away.
*/


#include <bits/stdc++.h>


int comparator(std::string s1,std::string s2){
    if (s1.length() > s2.length()) return 1;
    else if(s1.length() < s2.length()) return -1;
    return 0;
}

bool isOneAway(std::string s1,std::string s2){
    int c = 0;
    if (comparator(s1,s2) == 1){
        return s2.length() + 1 == s1.length() ? true : false;
    }
    else if (comparator(s1,s2) == -1) {
        return s1.length() - 1 == s2.length() ? true : false;
    }
    
    else if(comparator(s1,s2) == 0) {
        // O(n^2) solution where n is length of string
        // Optimize to O(n) using Knuth-Morris-Pratt (KMP) (do it later)
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length() ;j++){
                if (s1[i] == s2[j])
                    c++;
            }
        }
    }

    return c == s1.length() - 1 ? true :false;
}

int main(){
    std::string str1 = "pale";
    std::string str2 = "bake";
    isOneAway(str1,str2) ? std::cout << "true" : std::cout << "false";
	return 1;
}

