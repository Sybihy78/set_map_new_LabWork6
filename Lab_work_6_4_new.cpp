#include<iostream>


int* resize(int* parray, const int size, const int new_size) {

	int* pnew_arr = new int[new_size];
	*pnew_arr = *parray;
	delete[] parray;
	parray = nullptr;

	return pnew_arr;
	
	delete[] pnew_arr;
	pnew_arr = nullptr;

}


int main() {

	int SIZE;
	std::cout << "Enter size of memory area" << std::endl;
	std::cin >> SIZE;
	int* parr = new int[SIZE];

	int NEW_SIZE;
	std::cout << "Enter NEW size of memory area" << std::endl;
	std::cin >> NEW_SIZE;
	
	std::cout << *resize(parr, SIZE, NEW_SIZE) << std::endl;

	system("pause");
	return 0;
}