#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>

using namespace std;

// Shortcuts for "common" data types in contests typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
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

int main() {
	int numOfTest;
	scanf("%d", &numOfTest);
	char name [100];
	int attack, defend;
	string nameArray[10];
	int attackArray[10];
	int defendArray[10];

	while (numOfTest > 0) {
		REP(index, 0, 9)
		{
			scanf("%s %d %d", name, &attack, &defend);
			nameArray[index] = string(name);
			attackArray[index] = attack;
			defendArray[index] = defend;
		}

		int maxAttack = 0;
		int maxDefend = 0;
		REP(i, 0, 9)
		{
			REP(j, i+1, 9)
			{
				REP(k, j+1, 9)
				{
					REP(l, k+1, 9)
					{
						REP(m, l+1, 9)
						{
							int tmpAttack = attackArray[i] + attackArray[j] + attackArray[k] + attackArray[l] + attackArray[m];

							if (maxAttack <= tmpAttack) {
								int tmpDefend = 0;
								int tmpCount = 0;
								REP(index, 0, 9)
								{
									if (index != i && index != j && index != k && index != l && index != m) {

										tmpDefend += defendArray[index];
										tmpCount++;
									}
								}
								if (maxAttack < tmpAttack) {
									maxDefend = tmpDefend;
								} else {//equal
									if (maxDefend < tmpDefend) maxDefend = tmpDefend;
								}
								maxAttack = tmpAttack;

							}
						}
					}
				}
			}
		}
		int count = 0;
		REP(i, 0, 9)
		{
			REP(j, i+1, 9)
			{
				REP(k, j+1, 9)
				{
					REP(l, k+1, 9)
					{
						REP(m, l+1, 9)
						{
							int tmpAttack = attackArray[i] + attackArray[j] + attackArray[k] + attackArray[l] + attackArray[m];

							if (tmpAttack == maxAttack) {
								int tmpDefend = 0;
								int tmpCount = 0;
								REP(index, 0, 9)
								{
									if (index != i && index != j && index != k
											&& index != l && index != m) {
										tmpDefend += defendArray[index];
										tmpCount++;
									}
								}
								if (tmpDefend != maxDefend) continue;
								//print result here
								string maxAttackName[] = {nameArray[i], nameArray[j], nameArray[k], nameArray[l], nameArray[m]};

								string minAttackName[5];

								tmpCount = 0;
								REP(index, 0, 9) {
									if (index != i && index != j && index != k
											&& index != l && index != m) {
										minAttackName[tmpCount] =
												nameArray[index];
										tmpCount++;
									}
								}

								sort(maxAttackName, maxAttackName + 5);
								sort(minAttackName, minAttackName + 5);
								printf("Case %d:\n", ++count);
								printf("(%s, %s, %s, %s, %s)\n", maxAttackName[0].c_str(), maxAttackName[1].c_str(), maxAttackName[2].c_str(), maxAttackName[3].c_str(), maxAttackName[4].c_str());
								printf("(%s, %s, %s, %s, %s)\n", minAttackName[0].c_str(), minAttackName[1].c_str(), minAttackName[2].c_str(), minAttackName[3].c_str(), minAttackName[4].c_str());

							}
						}
					}
				}
			}
		}

		numOfTest--;
	}

	return 0;
}
