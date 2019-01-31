#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    //cout<<"Inside plus one"<<endl;
    int carry = 1;
    vector<int> v;
    for (int i = A.size() - 1; i >= 0; i--) {
        int sum = A[i] + carry;
        v.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry > 0) {
        v.push_back(carry);
    }
    
    reverse(v.begin(), v.end());
    /*
    cout<<"Printing"<<endl;
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
    */

    int nonZeroNumberIndex = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            break;
        }
        nonZeroNumberIndex++;
    }
    
    vector<int> res;
    for (int i = nonZeroNumberIndex; i < v.size(); i++) {
        res.push_back(v[i]);
    }

    return res;
}

int main() {

    vector<int> v;
    v.push_back(0);
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    
    vector<int> res = plusOne(v);

    
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";

    cout<<endl;

    return 0;
}
