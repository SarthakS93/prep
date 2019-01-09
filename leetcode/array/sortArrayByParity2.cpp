#include<iostream>
#include<vector>
using namespace std;

vector<int> sortByParity(vector<int> &v) {
    vector<int> a(v.size());
    int oddPos = 1, evenPos = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            a[evenPos] = v[i];
            evenPos += 2;
        }
        else {
            a[oddPos] = v[i];
            oddPos += 2;
        }
    }
    
    return a;
}

int main() {
    
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; 
        cin>>x;
        v.push_back(x);
    }

    vector<int> a = sortByParity(v);
    
    for (int i = 0; i < a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
