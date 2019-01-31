#include<iostream>
#include<vector>
using namespace std;

int maximumGap(const vector<int> &A) {
    int minimum = A[0], maxGap = -1, currentGap = 0;
    
    for (int i = 1; i < A.size(); i++) {
        
        if (A[i] >= minimum) {
            currentGap++;
            if (maxGap < currentGap) {
                maxGap = currentGap;
            }
        }
        else {
            minimum = A[i];
            currentGap = 0;
        }

    }
    

    return maxGap;
}


int main() {
    
    vector<int> v;
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(2);
    //v.push_back(1);

    cout<<maximumGap(v)<<endl;

    return 0;
}
