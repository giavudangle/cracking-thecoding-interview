/* 1.7.Rotate Matrix : Given an image represented by an NxN
where each pixels in the image is 4bytes.Wriate a method to
rotate the image by 90 degrees.
*/

/*
1 2 3
4 5 6
7 8 9
Rotate 90%:

*/

#include <iostream>
#include <vector>
const int MSIZE = 3;
int x;

void rotateMatrix(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& rotated)
{
	for (int i = 0; i < a.size(); i++) {
		for (int j = a.size() - 1; j >=0; j--) {
			rotated[i].push_back(a[j][i]);
		}
	}
}
void readMatrix(std::vector<std::vector<int>> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			std::cin >> x;
			a[i].push_back(x);
		}
	}
}

void printMatrix(std::vector<std::vector<int>> &a)
{
	for (auto x : a) {
		for (auto z : x) 
			std::cout << z << " ";	
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<std::vector<int>> a(MSIZE);
	std::vector<std::vector<int>> rotated(MSIZE);

	readMatrix(a);
	printMatrix(a);
	rotateMatrix(a, rotated);
	printMatrix(rotated);


	return 1;
}
