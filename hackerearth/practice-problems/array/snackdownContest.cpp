#include<iostream>
#include<set>
using namespace std;

int main() {

    int t, n, a[1000], b[1000];
    cin>>t;
    while (t--) {
        int k, n, m;
        set<int> bucket;
        cin>>k>>n;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            bucket.insert(a[i]);
        }
        cin>>m;
        for (int i = 0; i < m; i++) {
            cin>>b[i];
            bucket.insert(b[i]);
        }
        
        if (bucket.size() == k) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }

    }

    return 0;
}
