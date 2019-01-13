#include<iostream>
using namespace std;

int uniquePathsHelper(int curX, int curY, int m, int n, int board[101][101]) {
    if (curX >= m || curY >= n) {
        return 0;
    }
    else if (curX == m - 1 && curY == n - 1) {
        return 1;
    }

    if (board[curX][curY] != -1) {
        return board[curX][curY];
    }

    int op = uniquePathsHelper(curX + 1, curY, m, n, board) + uniquePathsHelper(curX, curY + 1, m, n, board);
    board[curX][curY] = op;
    return op;
}

int uniquePaths(int m, int n) {
    int board[101][101];
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            board[i][j] = -1;

    return uniquePathsHelper(0, 0, m, n, board);
}

int main() {

    int m, n;
    cin>>m>>n;

    cout<<uniquePaths(m, n)<<endl;

    return 0;
}
