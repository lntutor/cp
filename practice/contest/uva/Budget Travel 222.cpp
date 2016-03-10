#include<algorithm>
#include<cstdio>

#define REP(i, a, b) for(int i = a; i <=b; i++)

using namespace std;

double d;
double capacity, milePerGallon, firstCost;
int n;

double stationDistance[100];
double stationCost[100];

double solve(double currentDistance, int nextStation) {
	if (currentDistance + capacity*milePerGallon >=d) return 0;
	if (nextStation >= n) return 0;
	double best = 10000000;

	REP(i, nextStation, n-1) {
		double fuelUsed = (stationDistance[i] - currentDistance)/milePerGallon;
		if (capacity - fuelUsed < 0) break;

		if (capacity - fuelUsed <= capacity/2.0) {
			best = min(best, 200 + fuelUsed*stationCost[i] + solve(stationDistance[i], i + 1));
		} else if (capacity - fuelUsed > capacity/2.0 && stationDistance[i] > capacity*milePerGallon + currentDistance) {
			return 200 + fuelUsed*stationCost[i] + solve(stationDistance[i], i+1);
		}
	}

	return best;
}


int main() {

	int count = 0;
	while(true) {
		scanf("%lf", &d);
		if (d < 0) break;

		scanf("%lf %lf %lf %d", &capacity, &milePerGallon, &firstCost, &n);
		REP(i, 0, n-1) {
			scanf("%lf %lf", &stationDistance[i], &stationCost[i]);
		}
		printf("Data Set #%d\n", ++count);
        printf("minimum cost = $%.2f\n", firstCost + solve(0, 0)/100);


	}

}
