#include<iostream>
#include<cmath>

using namespace std;

bool checkIfNumberHas3Divisors(int n) {
    int ctr = 1;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            ctr++;
        }

        if (ctr > 3) {
            return false;
        }
    }

    if (ctr == 3) {
        return true;
    }
    else {
        return false;
    }
}


int main() {

    int n, k, a[1000006], b[1000006], max = 0;
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        if (a[i] > max) {
            max = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        
    }

    return 0;
}
