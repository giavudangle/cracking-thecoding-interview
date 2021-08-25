

/**
 * 1.8.Zero Matrix :
 * 
 * Write an algorithm such that if an element in an
 * M X N matrix is 0, it's entire row and column are
 * set to 0.
 * 
 * 
 * @author VuDang
 */
#include <iostream>
#include <vector>
#include <map>



typedef std::vector<std::vector<int>> td;
const int M_SIZE = 3;
const int MAX = (int)1e9 + 3;
void readMatrix(td& a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			int x;
			std::cin >> x;
			a[i].emplace_back(x);
		}
	}
}


void printMatrix(td& a) {
	for (auto x : a) {
		for (auto z : x) {
			std::cout << z << " ";
		}
		std::cout << "\n";
	}
}

std::map<int,int> findZero(td& a) {
	std::map<int, int> mem;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[i][j] == 0) {
				mem.insert({ i, j });
			}
		}
	}
	return mem;
}

td mapZero(td& a) {
	td clone = a;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[i][j] == 0) {
				int iRow = i, iCol = j;

				// Row
				for (int k = 0; k < a.size(); ++k) {
					clone[iRow][k] = 0;
				}
				// Col
				for (int k = 0; k < a.size(); ++k) {
					clone[k][iCol] = 0;
				}
			}
		}
	}
	return clone;
}

int main() {
//	td a(M_SIZE);
	td a{
		{1,1,1},
		{1,5,3},
		{2,1,0}
	};

	//readMatrix(a);
	findZero(a);
	td res = mapZero(a);
	printMatrix(res);


	return 1;
}

