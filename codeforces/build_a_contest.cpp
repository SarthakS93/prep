#include<iostream>
using namespace std;

int main() {

    int n, m, arr[100005], count[10005] = {0};
    cin>>n>>m;
    for (int i = 0; i < m; i++)
        cin>>arr[i];

    int ctr = 0;

    for (int i = 0; i < m; i++) {
        int item = count[arr[i]];
        if (item == 0) {
            count[arr[i]] += 1;
            ctr++;
        }
        else {
            count[arr[i]] += 1;
        }
        
        if (ctr == n) {
            cout<<1;
            for (int j = 1; j <= n; j++) {
                count[j] -= 1;
                if (count[j] == 0) {
                    ctr--;
                }
            }
        }
        else {
            cout<<0;
        }
    }

    cout<<endl;

    return 0;
}
