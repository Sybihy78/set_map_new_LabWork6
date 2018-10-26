#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<map>


int get_result(const std::string &path);
void get_result_in_file(const std::string &path);
bool test_your_number(const std::string &path, const std::string user);


int main() {

	std::string input = "2_input.txt";
	
	std::cout << get_result(input) << std::endl;
	get_result_in_file(input);
	
	std::cout << "What string of numbers do you want to find" << std::endl;
	std::string user_numbers;
	std::cin >> user_numbers;
	
	if (test_your_number(input, user_numbers) == true) {
		std::cout << "You number is found in the file" << std::endl;
	}
	else {
		std::cout << "You number is not found in the file" << std::endl;
	}
	
	system("pause");
	return 0;
}


int get_result(const std::string &path) {

	std::ifstream filein;
	filein.open(path);
	if (!filein.is_open()) {
		std::cout << "File is not found" << std::endl;
		return 0;
	}

	char tmp;
	std::set<char> symbols;
	while (filein >> tmp) {
		symbols.insert(tmp);
	}
	filein.close();
	return symbols.size();
}


void get_result_in_file(const std::string &path) {

	std::ifstream filein;
	filein.open(path);
	if (!filein.is_open()) {
		std::cout << "File is not found" << std::endl;
		return;
	}
	std::ofstream fileout;
	fileout.open("result.txt");

	char tmp;
	std::map<char, int> symbols_map;
	while (filein >> tmp) {
		++symbols_map[tmp];
	}
	filein.close();

	for (auto it = symbols_map.begin(); it != symbols_map.end(); ++it) {
		fileout << it->first << '\t' << it->second << '\n';
	}

	fileout.close();
	std::cout << std::endl;
}


bool test_your_number(const std::string &path, const std::string user) {
	
	std::ifstream filein;
	filein.open(path);
	if (!filein.is_open()) {
		std::cout << "File is not found" << std::endl;
		return 0;
	}

	std::string str = "abcdefghijklmnopqrstuvwxyz";
	char tmp;
	std::string number;
	std::set<std::string> my_numbers;

	while (filein >> tmp) {
		number += tmp;
		for (int i = 0; i < str.size(); ++i) {
			if (tmp == str[i]) {
				number.pop_back();
				my_numbers.insert(number);
				number.clear();
			}
		}
	}

	for (auto it = my_numbers.begin(); it != my_numbers.end(); ++it) {
		if (user == *it) {
			return true;
		}
	}
	return false;

	filein.close();
}