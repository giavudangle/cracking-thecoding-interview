

/**
 * 1.6.StringCompression :
 * 
 * Implement a method to perform basic string compression
 * using the count of repeated characters. For ex. the string
 * "aabcccccaaa" would become "a2b1c5a3". If the sum compressed string
 * does not become smaller then the original string, then your 
 * method should return the original string. You can assume that
 * the string has only upper case and lower case letters.
 * 
 * 
 * @author VuDang
 */

#include <bits/stdc++.h>





int main(){
    std::string s = "aabcccccaaa";
    std::stringstream ss("");
    std::string res;
    const int NUMBERS___CHARACTERS = 255;
    int counter [NUMBERS___CHARACTERS];

    for(int i=0;i<NUMBERS___CHARACTERS;i++){
        counter[i] = 0;
    }

    for(int i =0;i<s.length();i++){
        counter[(int)s[i]]++;
    }

    for(int i=0;i<NUMBERS___CHARACTERS;i++){
        if(counter[i] == 1) ss << (char)i;
        if(counter[i] > 1) {
            ss << (char)i;
            ss << counter[i];
        }
    }
  
    ss >> res;
    std::cout << res;
   
	return 1;
}

