#include<iostream>
using namespace std;

int partition(int a[], int start, int end) {
    int pivot = a[start], ctr = 0;

    for (int i = start + 1; i <= end; i++) {
        if (pivot > a[i]) {
            ctr++;
        }
    }

}

int main() {
    



    return 0;
}
