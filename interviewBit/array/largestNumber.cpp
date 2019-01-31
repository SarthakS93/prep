#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int getNumberOfDigits(int x) {
    int ctr = 1;
    while (x) {
        x /= 10;
        ctr++;
    }
    return ctr;
}

int createBigNumber(int a, int b) {
    int bDigits = getNumberOfDigits(b);
    a *= pow(10, bDigits - 1);
    return a + b;
}

bool isFirstNumberGreater(int a, int b) {
   int bigA = createBigNumber(a, b), bigB = createBigNumber(b, a);
   //cout<<bigA<<" and "<<bigB<<endl;
   return bigA > bigB;
}

string convertNumberToString(int a) {
    string s = "";
    //cout<<"Convert "<<a<<" to string"<<endl;
    if (a == 0) {
        s += "0";
    }
    else {
        while (a) {
            int x = a % 10;
            char c = x + '0';
            s.push_back(c);
            a /= 10;
        }

        for (int i = 0; i < s.size() / 2; i++) {
            char t = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = t; 
        }
    }
    return s;
}

string getLargestNumber(const vector<int> &A) {
    string s = "";
    vector<int> v(A);
    
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1; j++) {
            if (isFirstNumberGreater(v[j], v[j + 1])) {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
    }
    
    /*
    cout<<"Sorted numbers"<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    */

    if (v[v.size() - 1] == 0) {
        s = "0";
    }
    else {
        for (int i = v.size() - 1; i >= 0; i--) {
            s += convertNumberToString(v[i]);    
        }
    }
    
    return s;
}


int main() {
    
    vector<int> v;
    
    v.push_back(9);    
    v.push_back(99);
    v.push_back(999);
    v.push_back(9999);
    v.push_back(9998);
    cout<<getLargestNumber(v)<<endl;
    

    cout<<isFirstNumberGreater(9, 9998)<<endl;


    return 0;
}
