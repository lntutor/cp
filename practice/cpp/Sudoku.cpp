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

int board[9][9];

void printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int checkCol(int row, int col) {

    if (row == 3 && col == 1) {
        cout << " hello" << endl;
    }
    int array[10];

    memset(array, 0, sizeof(array));
    for (int k = 0; k < 9; k++) {
        if (array[0] == 9) return 1;
        else if (array[board[k][col]] == 1 && board[k][col] != 0)
            return 0;
        else
            array[board[k][col]]++;
    }
    return 1;
}

int checkRow(int row, int col) {
    if (row == 3 && col == 1) {
        cout << " hello" << endl;
    }
    int array[10];

    memset(array, 0, sizeof(array));
    for (int k = 0; k < 9; k++) {
        if (array[0] == 9) return 1;
        else if (array[board[row][k]] == 1 && board[row][k] != 0)
            return 0;
        else
            array[board[row][k]]++;
    }
    return 1;
}

int checSubSquare(int row, int col) {

    if (row == 3 && col == 1) {
        cout << " hello" << endl;
    }

    int array[10];
    memset(array, 0, sizeof(array));

    int subSquareIndexRow = row / 3;
    int subSquareIndexCol = col / 3;

    for (int i = subSquareIndexRow; i < subSquareIndexRow + 3; i++) {
        for (int j = subSquareIndexCol; j < subSquareIndexCol + 3; j++) {
            if (array[0] == 9) return 1;
            else if (array[board[i][j]] == 1 && board[i][j] != 0)
                return 0;
            else
                array[board[i][j]]++;
        }
    }
    return 1;
}

int checkValid(int row, int col) {
    return checkCol(row, col) && checkRow(row, col) && checSubSquare(row, col);
}

void generateValidSubSquare(int row, int col) { //row & col index of sub square
    vector<int> array;
    for (int i = 1; i <= 9; i++)
        array.push_back(i);

    row *= 3;
    col *= 3;

    std::random_shuffle(array.begin(), array.end());
    //  cout << row << " " << col << endl;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            //          cout << i << " " << j << endl;
            board[i][j] = array.back();
            array.pop_back();
        }
    }
}

int checkBoardValid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!checkValid(i, j))
                return 0;
        }
    }
    return 1;
}

void resetRowCol(int row, int col) {

    for (int i = 0; i < 9; i++)
        board[row][i] = 0;
    for (int i = 0; i < 9; i++)
        board[i][col] = 0;
}

void resetSubSquare(int row, int col) {
    row *= 3;
    col *=3;
    cout << "resetSubSquare " << endl;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            board[i][j] = 0;
        }
    }
}

int isBoardFullFill() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

void generateValidBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            generateValidSubSquare(i, j);
            cout << "*****************" << endl;
            printBoard();
            cout << "*****************" << endl;
            while(!checkBoardValid()) {
                resetSubSquare(i, j);
                generateValidSubSquare(i, j);
            }
            if (isBoardFullFill()) {
                printBoard();
                return;
            }
        }
    }
}

int main() {
    generateValidBoard();
    return 1;
}
