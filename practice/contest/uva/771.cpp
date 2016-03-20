#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
		for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
		for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
		for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
typedef vector<int> vi;

#define MaxM 500
int MIN = INF;
int T, M, K;
int myArray[MaxM];

bool calPageOfLastScribe(int page);

void BS(int low, int high) {
	if (low >= high) {
//		cout << MIN << endl;
		return;
	}

	int mid = low + (high - low) / 2;

//	int lastScriberSum = calPageOfLastScribe(mid);

	if (!calPageOfLastScribe(mid)) {
		BS(low, mid);
	} else {
		BS(mid, high);
	}

}

int OPTIMAL_PAGE = INF;

bool calPageOfLastScribe(int page) { // return false ==> search on left. true ==> right
	double sum = 0;
	int scribers = 0;
	int maxPage = 0;
	REP(i, 0, M -1)
	{
		sum += myArray[i];
		if (sum > page) {
			sum = myArray[i];
			scribers++;
		} else if (i==M-1) {
			scribers++;
		}
	}
	if (scribers < K) return false;
	if (scribers > K) return true;
	if (scribers == K) {
		int maxPage = 0;
		REP(i, 0, M -1)
		{
			sum += myArray[i];
			if (sum > page && i!= M-1) {
				sum -= myArray[i];
				if (sum > maxPage) maxPage = sum;
				sum = myArray[i];
			} else if (i==M-1) {
				if (sum > maxPage) maxPage = sum;
			}
		}
		if (OPTIMAL_PAGE > maxPage) {
			OPTIMAL_PAGE = maxPage;
			return true;
		} else {
			return false;
		}
	}

}

int main() {
scanf("%d", &T);

while (T--) {
	scanf("%d%d", &M, &K);
	double sum = 0;

	REP(i, 0, M-1)
	{
		cin >> myArray[i];
		sum += myArray[i];
	}
	BS(1, sum);

//		int average = sum/K;
//		cout << average << endl;

	sum = 0;
	REP(i, 0, M-1)
	{
		sum += myArray[i];
		if (sum > OPTIMAL_PAGE && i != M - 1) {
			sum = myArray[i];
			cout << "/ " << myArray[i] << " ";
		} else {
			if (i == M - 1)
				cout << myArray[i] << endl;
			else
				cout << myArray[i] << " ";
		}
	}

}
return 0;
}
