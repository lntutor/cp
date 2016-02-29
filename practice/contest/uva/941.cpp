#include <iostream>
#include <algorithm>

using namespace std;

string result;

int fac (int n) {
	if (n==1) return 1;
	else return n * fac(n-1);
}

void solve(string& value, int order, int index){
	//solve from index = 0 until value is empty
	// everytime we choose a char from `value`,
	//we remove it from `value` and continue to solve from the `reduced-value`
	// we store result in `result` global variable

	if (value.length() == 1) {
		result[result.length()-1] = value[0];
		return;
	}

	int temp = fac(value.length() - 1);

	int group = order/temp;
	result[index] = value[group];

	int newOrder = order - group*temp;//
	string newValue = value.erase(group, group);

	solve(newValue, newOrder, ++index);
}


int main() {
	int n, order;
	string value;
	cin >> n;

	while(n--){
		cin >> value;
		cin >> order;
		sort(value.begin(), value.end());
		result = value;
		solve(value, order, 0);//solve from 0 until length - 1
		cout << result << endl;
	}
	return 0;
}
