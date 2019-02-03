#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n, q;
    vector<int> v;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>q;
        v.push_back(q);
    }
    cin>>q;
    
    int typeOfQuery, pos, val;
    while (q > 0) {
        cin>>typeOfQuery;
        if (typeOfQuery == 1) {
            cin>>pos>>val;
        }
        else {
            cin>>pos;
        }

    }
    
    return 0;
}
