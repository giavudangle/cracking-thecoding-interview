/* 1.3.URLify : Write a method to replace all spaces in a string with '%20'.You may
assume that the string has sufficient space at the end to hold the addtional characters,
and that you are given the "true" length of the string.
*/


#include <bits/stdc++.h>
using namespace std;

string ReplaceSolve(string s,int length) {
    for(int i = 0;i<length;i++)
        if(char(s[i]) == 32) 
            s.replace(i,1,"%20");
        
    
    return s;
}

int main()
{  
    string s ="Mr John Smith   ";
    cout << ReplaceSolve(s,s.length());
    return 0;
}