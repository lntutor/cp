#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define TRvii(c, it) \
		for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int ROW = 5;
int COL = 5;

int matrix[5][5] = {
                    {1,2,3,4,5},
                    {16,17,18,19,6},
                    {15,24,25,20,7},
                    {14,23,22,21,8},
                    {13,12,11,10,9}
                  };

void spriral(int M, int N) {
  int row = 0;
  int col = 0;

  while(row >= 0 && col >=0 && row < M && col < N) {
    //first row
    for (int i = col; i < N; i++) {
      cout << matrix[row][i] << " ";
    }
    row++;

    //last column
    for (int i = row; i < M; i++) {
      cout << matrix[i][N-1] << " ";
    }
    N--;

    //last row
    // cout << " N = " << N << " M = " << M << endl;
    for (int i = N-1; i>= col; i--) {
        cout << matrix[M-1][i]  << " ";
    }
    M--;

    // cout << " N = " << N << " M = " << M << endl;
    //first column
    for (int i = M-1 ; i >=row; i--) {
        // cout << i << N - 1 << endl;
        cout << matrix[i][col]  << " ";
    }
    col++;
  }

}

int main() {
  spriral(5, 5);
  return 1;
}
