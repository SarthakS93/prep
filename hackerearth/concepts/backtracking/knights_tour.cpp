#include<iostream>
using namespace std;

bool isMoveValid(int x, int y, int board[8][8]) {
    if (board[x][y] != -1 || x >= 8 || x < 0 || y >= 8 || y < 0) 
        return false;
    else 
        return true;
}

bool traverseBoard(int board[8][8], int x, int y, int moveX[8], int moveY[8], int moveNumber) {
    if (moveNumber == 64) {
        return true;
    }    

    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i], nextY = moveY[i] + y;
        if (isMoveValid(nextX, nextY, board)) {
            board[nextX][nextY] = moveNumber;
            if (traverseBoard(board, nextX, nextY, moveX, moveY, moveNumber + 1)) {
                return true;
            }
            else {
                board[nextX][nextY] = -1;
            }
        }
    }
    return false;
}


int main() {

    int board[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = -1;
    
    int moveX[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int moveY[8] = {2, 1, -1, -2, 2, 1, -1, -2};

    board[0][0] = 0;

    bool isSolved = traverseBoard(board, 0, 0, moveX, moveY, 1);

    if (isSolved) {
        cout<<"Solved"<<endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] < 10) {
                    cout<<"0";
                }
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else {
        cout<<"No Solution"<<endl;
    }

    return 0;
}
