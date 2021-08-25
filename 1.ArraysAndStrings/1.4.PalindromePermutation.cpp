
/**
 * 1.4. Palindrome Permutation : Given a string, write a function to check if it
 * is a permutation of a palindrome.A palindrome is a word or phrase that is the same fowards
 * and backwards.A permutation is rearrangement of letters.The palindrome does not need to be 
 * limited to just dictionary words.
 * 
 * ex. Input : Tact Coa
 * Output : True (permutations : "taco cat", "atco cta", etc.) 
 * 
 * 
 * @author VuDang
 */

#include <bits/stdc++.h>
const int CHAR_NUMS = 256;
int main(){
    
    std::string str = "ttca";
    int c = 0;
    std::vector<char> counter = std::vector<char>(CHAR_NUMS);
    for(int i=0;i <str.length();i++){
        if(str[i] == ' ') continue;
        counter[str[i]]++;
    }

    for (int i=0;i<CHAR_NUMS;i++){
        if(counter[i] == 1)
            c++;
    }
    c > 1 ? std::cout<< "No" : std::cout<< "Yes";


    return 1;
} 

