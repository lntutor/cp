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
#define REP(i, a, b) for(int i = a; i <= b; i++)
int T;

string line;

int solve(int begin, int end, char signal) {
	if (begin == end && line[begin] == signal) return 0;
	if (begin == end && line[begin] != signal) return 1;

	int differentIndex = -1;
	bool foundDiff = false;
	for(int i = end; i > begin; i--) {
		if (line[i] != line[i-1]) {
			foundDiff = true;
			differentIndex = i-1;
			break;
		}
	}

	if (foundDiff) {
		char lastDiffChar = line[differentIndex+1];
		return solve(begin, differentIndex, lastDiffChar) + solve(differentIndex+1, end, signal);
	}
	if (signal != line[begin]) return 1;

	return 0;
}

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
		int result = solve(0, line.length()-1, '+');
		outFile << "Case #" << i << ":" << " " << result << endl;

	}
	outFile.close();
}
