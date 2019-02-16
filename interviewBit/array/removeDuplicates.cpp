#include<iostream>
#include<vector>
using namespace std;

// 1 1 2 3 3

int removeDuplicates(vector<int> &a) {
    int j = 0, i = 0, n = a.size();
    
    for (i = 0; i < n; i++) {
        if (i < n - 1 && a[i] == a[i + 1]) {
            continue;
        }
        else {
            a[j] = a[i];
            j++;
        }
    }
    return j;
}


int main() {
    
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    
    int size = removeDuplicates(v);

    for (int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
