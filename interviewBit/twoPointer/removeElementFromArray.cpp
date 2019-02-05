#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int low = 0, high = A.size() - 1;
    while (low <= high) {
        if (A[low] != B) {
            low++;
        }
        else if (A[high] != B) {
            high--;
        }
        else {
            break;
        }
    }
    
    int res = A.size() - (high - low + 1);
    //cout<<"low: "<<low<<" high: "<<high<<" res: "<<res<<endl; 
    
    int index = high + 1;
    while (index < A.size()) {
        A[low] = A[index];
        low++;
        index++;
    }

    return res;
}

// 4 1 1 2 1 3
//
// 1 1 1 2 3 4
//
// low = 0
// high = 2
//
// res = high - low + 1

int main() {

    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter n values"<<endl;
    for (int i = 0; i < n; i++)
        cin>>v[i];

    cout<<"Enter b"<<endl;
    int b;
    cin>>b;
    
    int res = removeElement(v, b);
    
    cout<<"Result is: "<<res<<endl;
    cout<<"Proceesed Array is: "<<endl;
    for (int i = 0; i < res; i++)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}
