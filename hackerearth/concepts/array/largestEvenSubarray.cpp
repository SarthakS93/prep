#include<iostream>
using namespace std;

int main() {

    int t, n, a[1000006];
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i = 0; i < n; i++)
            cin>>a[i];
        
        bool containsAtleastOneEven = false;
        int maxCtr = 0, ctr = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                ctr++;
                containsAtleastOneEven = true;
                if (ctr > maxCtr) {
                    maxCtr = ctr;
                }
            }
            else {
                ctr = 0;
            }
        }
        
        if (!containsAtleastOneEven) {
            cout<<-1<<endl;
        }
        else {
            cout<<maxCtr<<endl;
        }
    
    }

    return 0;
}
