/*
1.1-IsUnique : Implement an algorithm to determine if a string has all
unique characters.What if you cannot use addtional data structures ?
*/

#include <bits/stdc++.h>
using namespace std;

// O(n^2) implementation
bool checkUnique(string s)
{
    for (int i = 0; i < s.length() - 1; i++)
        for (int j = i + 1; j < s.length(); j++)
            if (s[i] == s[j])
                return false;
    return true;
}
// O(nlogn) implementation O(n^n) in worst case (Quicksort)
bool isUnique(string s)
{
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == s[i + 1])
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;

    if (isUnique(s))
        cout << "true";
    else
        cout << "false";
    
}