/**
 * 1.2-Check Permutation : Given two strings,write a method to decide 
 * if one is a permutation of the other
 *  
 * Quicksort (sort() in std maybe got O(n^2) in worst case)
 * Merge sort is more efficient and works faster than quick sort in
 * case of larger array size or datasets
 * Quick sort is more efficient and works faster than merge sort in
 * case of smaller array size or datasets.
 * 
 * @author VuDang
 */
#include <bits/stdc++.h>
using namespace std;

bool Solve(string a, string b)
{
    if (a.length() != b.length())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int main()
{
    string a, b;
    cin >> a >> b;
    Solve(a, b) ? cout << "True" : cout << "False";
    return 0;
}