#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> wave(vector<int> &A) {
    vector<int> v(A);
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i += 2) {
        int t = v[i];
        v[i] = v[i + 1];
        v[i + 1] = t;

    }
    
    return v;
}


int main() {
    
    int n;
    vector<int> v;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<int> res = wave(v);

    for (int i = 0; i < n; i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}
