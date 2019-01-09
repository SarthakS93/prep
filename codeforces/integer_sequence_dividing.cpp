#include<iostream>
using namespace std;

int main() {
    
    long long n;
    cin>>n;
    
    int mod = n % 4;
    if (mod == 1 || mod == 2) {
        cout<<"1"<<endl;
    } 
    else {
        cout<<"0"<<endl;
    }

    return 0;
}
