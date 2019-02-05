#include<vector>
#include<iostream>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    int low = 0, high = (A.size()*A[0].size()) - 1;

    while (low <= high) {
        int mid = (low + high)/2;
        int row = mid / A[0].size(), col = mid % A[0].size();
        cout<<"Low: "<<low<<" and High: "<<high<<endl;
        cout<<"Row: "<<row<<" and Col: "<<col<<" and MID: "<<mid<<" and element"<<A[row][col]<<endl;
        if (A[row][col] == B) {
            return 1;
        }
        else if (A[row][col] > B) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return 0;
}

int main() {

    int rows, cols, x;
    cin>>rows>>cols;
    vector<vector<int> > mat;
    
    for (int i = 0; i < rows; i++) {
        vector<int> v;
        for (int j = 0; j < cols; j++) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        mat.push_back(v);
    }

    cin>>x;

    cout<<"Search for "<<x<<endl;

    cout<<searchMatrix(mat, x)<<endl;

    return 0;
}
