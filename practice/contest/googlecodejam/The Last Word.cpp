#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define MaxN 2005
#define REP(i, a, b) for(int i = a; i <= b; i++)

int T, N;

string line;

int main() {
	ofstream outFile;
	outFile.open("large_output.txt");

	ifstream infile;
	infile.open("large_input.txt");
	long long T;
	string test;
	std::getline(infile, test);
	std::stringstream ss(test);
	ss >> T;

	REP(i, 1, T)
	{
		std::getline(infile, line);
		std::stringstream ss(line);
		string result = "";
		REP(j, 0, line.length()-1) {
			int length = result.length();
			if (j == 0 || line[j] >= result[0]) result.insert(0, 1, line[j]);
			else result.insert(length, 1, line[j]);
		}
		outFile << "Case #" << i << ":" << " " << result << endl;

	}

	outFile.close();
}
