/* 1.9.String Rotation : Assume you have a method isSubstring which checks if 
* one word is a substring of another. Given two string : s1,s2, write code to check 
* if s2 is a rotation of s1 using only one call to isSubstring
* e.g : erbottewat is a rotation of waterbottle
*/


#include <iostream>



int main() {

	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";

	bool flag = false;

	if (s1.length() != s2.length()) flag = false;

	std::string comp = s1.append(s1);

	if (comp.find(s2) != std::string::npos) flag = true;

	flag == true ? std::cout << "Yes" : std::cout << "No";


	return 1;
}

