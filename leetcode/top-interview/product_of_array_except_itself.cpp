#include<iostream>
#include<vector>
using namespace std;

/*
 *  1    2    3    4
 *  
 *  24   12   8    6 
 *
 *  1    1    2    6
 *
 *  24   12   4    1 
 *
 *  24   12   8    6 
 *
 */

vector<int> getProductArray(vector<int> v) {
    vector<int> temp1(v.size()), temp2(v.size());
    temp1[0] = 1;
    temp2[v.size() - 1] = 1;

    for (int i = 0; i < v.size() - 1; i++) 
        temp1[i + 1] = temp1[i] * v[i]; 
   
    for (int i = v.size() - 1; i > 0; i--) 
        temp2[i - 1] = temp2[i] * v[i];

    for (int i = 0; i < v.size(); i++) 
        temp1[i] = temp1[i] * temp2[i];
    
    return temp1;
}

vector<int> getProductArrayOptimized(vector<int> v) {
    vector<int> temp(v.size());
    temp[v.size() - 1] = 1;

    for (int i = v.size() - 1; i > 0; i--) 
        temp[i - 1] = temp[i] * v[i];

    int left = 1;
    for (int i = 0; i < v.size(); i++) {
        temp[i]  = temp[i] * left;
        left = left * v[i];
    }
    
    return temp;
}

int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];

    vector<int> productArray = getProductArrayOptimized(v);
    
    for (int i = 0; i < productArray.size(); i++) {
        cout<<productArray[i]<<" ";
    }
    cout<<endl;

    return 0;
}
