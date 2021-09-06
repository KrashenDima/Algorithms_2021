#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string concr_file(string str, size_t size_of_tab, string tab) {
	string sp = string(size_of_tab, ' ');
	size_t pos = 0;
	while ((pos = str.find(tab, pos)) != std::string::npos)
			str.replace(pos, tab.size(), sp);
	return str;
}

bool concr_file(char const * filename, size_t size_of_tab, string tab)
{
	ifstream fin(filename);
	if (!fin.is_open())
		return false;

	
	string temp_file = string(filename) + ".temp";
	ofstream fout(temp_file);
	if (!fout.is_open())
		return false;

	while (!fin.eof()) {
		string str;
		getline(fin, str);
		fout << concr_file(str, size_of_tab, tab) << endl;
	}

	fin.close();
	fout.close();

	
	remove(filename);
	
	return !rename(temp_file.c_str(), filename);
}


int main(int argc, char * argv[]) {
	for (int i = 1; i < argc; ++i)
		concr_file(argv[i], 4, "#");
	return 0;
}