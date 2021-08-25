/**
 * 1.1.IsUnique
 *  
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use any additional data structure?
 * 
 * ASCII v/s UNICODE - String can be either of these. ASCII has basically 128
 * characters (256 in a extended set) ranging from 0 - 127 whereas, UNICODE is
 * a superset of ASCII and has 0 - 2^21 characters. Only difference is size. 
 * 
 * 
 *  
 * @author VuDang
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
// std::sort -> O(nlogn) implementation - O(n^n) in worst case
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