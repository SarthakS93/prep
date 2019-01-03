#include<iostream>
using namespace std;

int findPivot(int a[], int low, int high, int size) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (mid < high && a[mid] > a[mid + 1]) {
        return mid;
    }
    else if (mid > low && a[mid] < a[mid - 1]) {
        return mid - 1;
    }

    int ans = findPivot(a, low, mid - 1, size);

    return ans != -1 ? ans : findPivot(a, mid + 1, high, size);

}



int main() {
    
    int a[] = {5, 6, 1, 2, 3, 4};
    
    int pivot = findPivot(a, 0, 5, 6);
    cout<<pivot<<endl;

    return 0;
}
