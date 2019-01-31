#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int> > mat) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void setZeroes(vector<vector<int> > &A) {
    bool isFirstRowZero = false, isFirstColZero = false;
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < n; i++) {
        if (A[0][i] == 0) {
            isFirstRowZero = true;
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        if (A[i][0] == 0) {
            isFirstColZero = true;
            break;
        }
    }

    cout<<isFirstRowZero<<" row and "<<isFirstColZero<<" col"<<endl;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }

    cout<<"After first step"<<endl;
    print(A);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }

    if (isFirstRowZero) {
        for (int i = 0; i < n; i++) {
            A[0][i] = 0;
        }
    }

    cout<<"First Row Op"<<endl;
    print(A);

    if (isFirstColZero) {
        for (int i = 0; i < m; i++) {
            A[i][0] = 0;
        }
    }

    cout<<"First col Op"<<endl;
    print(A);

}

int main() {

    int m, n;
    vector<vector<int> > mat;
    cin>>m>>n;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        mat.push_back(v);
    }

    setZeroes(mat);
    
    cout<<"Final Answer"<<endl;
    print(mat);

    return 0;
}
