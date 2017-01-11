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

#define REP(i, a, b) for(int i = a; i <= b; i++)

int T, N;

long long COUNT = 0;

bool loop(int diceSize, int loopSize, int currentSum, int target) {

  if (currentSum >= target) {
    COUNT = COUNT + pow(diceSize, loopSize);
    return true;
  }

  if (loopSize == 0) {
    return false;
  }
  for (int i = 1; i <=diceSize; i++) {
    loop(diceSize, loopSize-1, currentSum + i, target);
  }
  return false;
}

double solve(int diceSize, int loopSize, int currentSum, int target) {
  COUNT = 0;
  loop(diceSize, loopSize, currentSum, target);
  return COUNT / pow(diceSize, loopSize);
}

int getAddedValue(string str, int addedValue) {
  // cout << str << endl;
  for (int i = 0; i < 80; i++) {
    if (str[i]=='-') {

      return -addedValue;
    } else if (str[i] == '+') {
      return addedValue;
    }
  }
  return addedValue;
}

int main() {
	ofstream myfile;
	myfile.open("output.txt");
	FILE * pFile = fopen("input.txt", "r+");

	fscanf(pFile, "%d", &T);

	REP(i, 1, T)
	{
    int H, S;
		fscanf(pFile, "%d", &H);
		fscanf(pFile, "%d", &S);
    cout << H << " " << S << endl;
    char str [80];
    double maxProbability = 0;

    REP(j, 1, S) {
      fscanf(pFile, "%s", str);
      string myString(str);
      cout << myString << endl;
      char *pch = strtok (str,"d+-");
      int count = 0;
      int loopSize, diceSize, addedValue = 0;
      while (pch != NULL)
      {
        if (count == 0) {
          loopSize = atoi(pch);
        } else if (count == 1) {
          diceSize = atoi(pch);
        } else if (count == 2) {
          addedValue = atoi(pch);
        }
        count++;
        pch = strtok (NULL, "d+-");
      }

      addedValue = getAddedValue(myString, addedValue);
      cout << loopSize << " " << diceSize << " " << addedValue << endl;
      double currentProb = solve(diceSize, loopSize, 0, H - addedValue);
      if (currentProb > maxProbability) maxProbability = currentProb;
    }

    char buffer [50];
    sprintf (buffer, "%.6f", maxProbability);
    cout << "Case #" << i << ":" << " " << buffer << endl;
    myfile << "Case #" << i << ":" << " " << buffer << endl;
	}
	myfile.close();
}
