#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <istream>
#include <sstream>

using namespace std;

int main() {

	ofstream outFile;
	outFile.open("large_output.txt");

	ifstream infile;
	infile.open("large_input.txt");

	long long T, n, v1[1000], v2[1000];
	string line;
	std::getline(infile, line);
	std::stringstream ss(line);
	ss >> T;

	for (int t = 1; t <= T; t++) {
		getline(infile, line);
		std::stringstream ssn(line);
		ssn >> n;
		getline(infile, line);
		std::stringstream ssline1(line);
		int value;
		int count = 0;
		while (ssline1 >> value) {
			v1[count] = value;
			count++;
		}
		getline(infile, line);
		std::stringstream ssline2(line);

		count = 0;
		while (ssline2 >> value) {
			v2[count] = value;
			count++;
		}
		sort(v1, v1 + n);
		sort(v2, v2 + n);
		long long p = 0;
		for (int i = 0; i < n; i++) {
			p += (long long)v1[i] * (long long)v2[n - i - 1];
		}
		outFile << "Case #" << t << ": " << p << endl;
	}
	outFile.close();
	return 0;
}
