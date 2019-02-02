#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void sortColors(vector<int> &A) {
    int i = 0, j = 0, k = A.size() - 1;
    while (j <= k) {
        if (A[j] == 0) {
            A[j] = A[i];
            A[i] = 0;
            i++;
            j++;
        }
        else if (A[j] == 2) {
            A[j] = A[k];
            A[k] = 2;
            k--;
        }
        else {
            j++;
        }
    }

}


int main() {

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    
    sortColors(v);

    print(v);

    return 0;
}
