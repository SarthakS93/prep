#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr) {
    if (arr.size() <= 1) {
        return 0;
    }

    int low = 0, high = arr.size() - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        //cout<<"Low: "<<low<<" High: "<<high<<" Mid: "<<mid<<endl;
        if (mid < high && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        else if (mid > low && arr[mid] < arr[mid - 1]) {
            return mid - 1;
        }
        else if (arr[low] > arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return -1;
}


int findMinimumElementInRotatedArray(vector<int> v) {
    int pivotIndex = findPivot(v);
    return v[pivotIndex + 1];
}

int main() {

    vector<int> v;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
     
    cout<<findPivot(v)<<endl;
    cout<<findMinimumElementInRotatedArray(v)<<endl;

    return 0;
}
