#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef vector<int> vi;

int main() {
	int front, rear;
	while (scanf("%d", &front), front) {
		scanf("%d", &rear);
		vi frontVector(0);
		vi rearVector(0);
		REP(i, 0, front -1)
		{
			int teeth;
			scanf("%d", &teeth);
			frontVector.push_back(teeth);
		}

		REP(i, 0, rear -1 )
		{
			int teeth;
			scanf("%d", &teeth);
			rearVector.push_back(teeth);
		}

		vector<double> dVector(0);

		REP(i, 0, front - 1)
		{
			REP(j, 0, rear - 1)
			{
				double tmp = (double) frontVector[i] / rearVector[j];
				dVector.push_back(tmp);
			}
		}
		sort(dVector.begin(), dVector.end());
		double max = 0;
		for (std::vector<double>::iterator it = dVector.begin();
				it != dVector.end() - 1; it++) {
			double val = *(it + 1) / (*it);
			if (max < val)
				max = val;
		}
		printf("%.2lf\n", max);
	}

	return 0;
}
