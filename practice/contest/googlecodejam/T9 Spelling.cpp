#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; i++)

int t, n, c;
std::map<char, int> dict;

int main() {
	dict['a'] = 2;
	dict['b'] = 22;
	dict['c'] = 222;

	dict['d'] = 3;
	dict['e'] = 33;
	dict['f'] = 333;

	dict['g'] = 4;
	dict['h'] = 44;
	dict['i'] = 444;

	dict['j'] = 5;
	dict['k'] = 55;
	dict['l'] = 555;

	dict['m'] = 6;
	dict['n'] = 66;
	dict['o'] = 666;

	dict['p'] = 7;
	dict['q'] = 77;
	dict['r'] = 777;
	dict['s'] = 7777;

	dict['t'] = 8;
	dict['u'] = 88;
	dict['v'] = 888;

	dict['w'] = 9;
	dict['x'] = 99;
	dict['y'] = 999;
	dict['z'] = 9999;
	dict[' '] = 0;

	ofstream myfile;
	myfile.open("large_output.txt");
	ifstream infile;
	infile.open("large_input.txt");

	std::string line;
	std::getline(infile, line);
	std::stringstream ss(line);
	ss >> t;

	cout << t << endl;

	REP(i, 1, t)
	{
		getline(infile, line);
		char lastChar = -1;
		myfile << "Case #" << i << ":" << " ";
		cout << line << endl;
		REP(j, 0, line.length()-1)
		{
			char runningChar = line[j];
			if ((dict[runningChar] - dict[lastChar]) % 10 == 0) {
				myfile << " " << dict[runningChar];
			} else {
				myfile << dict[runningChar];
			}
			lastChar = runningChar;
		}
		myfile << endl;

	}
	myfile.close();
}
