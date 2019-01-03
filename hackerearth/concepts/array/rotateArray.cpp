#include<iostream>
using namespace std;

int main() {

    int a[1000006], b[1000006], t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for (int i = 0; i < n; i++)
            cin>>a[i];
        
        if (k > n) {
            k = k % n;
        }

        for (int i = 0; i < n; i++) {
            int index = (i + k) % n;
            b[index] = a[i];
        }
        for (int i = 0; i < n; i++) {
            cout<<b[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
