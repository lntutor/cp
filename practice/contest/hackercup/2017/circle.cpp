#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define MaxN 2005
#define PI 3.14159265
#define REP(i, a, b) for(int i = a; i <= b; i++)

int T, N;


bool solve(int p, int x, int y) {// return false for white, true for black
  if (p == 0) {
    return false;
  }
  bool isInCircle = (x - 50) * (x - 50) + (y - 50) * (y - 50) <= 2500;
  double realAngle = abs(atan2 (y,x) * 180 / PI - 90);

  // cout << "realAngle = " << realAngle << endl;
  bool isInSector = 100*realAngle/360 <= p;

  return isInCircle && isInSector;

}

int main() {
	ofstream myfile;
	myfile.open("output.txt");
	FILE * pFile = fopen("input.txt", "r+");

	fscanf(pFile, "%d", &T);

	REP(i, 1, T)
	{
    int p, x, y;
		fscanf(pFile, "%d", &p);
		fscanf(pFile, "%d", &x);
		fscanf(pFile, "%d", &y);
		bool result = solve(p, x, y);
		if (result)
			myfile << "Case #" << i << ":" << " " << "black" << endl;
		else
			myfile << "Case #" << i << ":" << " " << "white" << endl;

	}
	myfile.close();
}
