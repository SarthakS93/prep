#include<iostream>
#include<vector>
using namespace std;

vector<int> maxOnes(vector<int> &A, int k) {
    int left = 0, right = 0, maxLength = 0, startIndex = 0, ctr = 0;

    while (right < A.size()) {
        if (A[right] == 0) {
            ctr++;
        }

        while (ctr > k) {
            if (A[left] == 0) {
                ctr--;
            }
            left++;
        }

        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            startIndex = left;
        }

        right++;
    } 
    
    vector<int> res;

    for (int i = 0; i < maxLength; i++) {
        res.push_back(i + startIndex);
    }

    return res;
}

int main() {

    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];

    vector<int> res = maxOnes(v, k);

    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
