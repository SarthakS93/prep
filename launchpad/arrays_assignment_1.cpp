#include<iostream>
#include<unordered_map>
using namespace std;


void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


int merge(int a[], int n, int b[], int m, int c[]) {
    int i = 0, k = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    if (j == m) {
        while (i < n) {
            c[k] = a[i];
            i++;
            k++;
        }
    }
    else if (i == n) {
        while (j < m) {
            c[k] = b[j];
            j++;
            k++;
        }
    }

    return k;
}

void mergeSort(int a[], int n) {
    if (n <= 1) {
        return;
    }
    
    int l1 = n/2;
    int b[l1 + 1], c[l1 + 1];
    for (int i = 0; i < l1; i++) {
        b[i] = a[i];
    }
    for (int i = l1; i < n; i++) {
        c[i - l1] = a[i];
    }

    mergeSort(b, l1);
    mergeSort(c, n - l1);
    merge(b, l1, c, n - l1, a);
}

int takeArrayInput(int a[]) {
    cout<<"Enter size"<<endl;
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" elements"<<endl;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    return n;
}

void sort() {
    int a[100];
    int n = takeArrayInput(a);
    mergeSort(a, n);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void intersectionOf2Arrays() {
    int a[100], b[100], c[100];
    int n = takeArrayInput(a), m = takeArrayInput(b);
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++) {
        if (mymap.count(a[i]) == 0) {
            mymap[a[i]] = 1;
        }
        else {
            mymap[a[i]] = mymap[a[i]] + 1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (mymap.count(b[i]) > 0 && mymap[b[i]] > 0) {
            mymap[b[i]] = mymap[b[i]] - 1;
            cout<<b[i]<<" ";
        }
    }
    cout<<endl;
}

void findPairsWhichSumToX() {
    int a[100];
    int n = takeArrayInput(a);
    int x;
    cout<<"Enter x"<<endl;
    cin>>x;
    mergeSort(a, n);
    int low = 0, high = n - 1;
    while (low < high) {
        int sum = a[low] + a[high];
        if (sum < x) {
            low++;
        }
        else if (sum > x) {
            high--;
        }
        else {
            cout<<a[low]<<", "<<a[high]<<endl;
            low++; 
            high--;
        }
    }
}

void findTripletsSum() {
    int a[100];
    int n = takeArrayInput(a);
    int x;
    cout<<"Enter x"<<endl;
    cin>>x;
    mergeSort(a, n);
    for (int i = 0; i < n - 2; i++) {
        int low = i + 1, high = n - 1;
        while (low < high) {
            int sum = a[low] + a[high] + a[i];
            if (sum < x) {
                low++;
            }
            else if (sum > x) {
                high--;
            }
            else {
                cout<<a[i]<<", "<<a[low]<<", "<<a[high]<<endl;
                low++;
                high--;
            }
        }
    }

}


int main() {

    //intersectionOf2Arrays();
    //sort();
    //findPairsWhichSumToX();
    findTripletsSum();

    return 0;
}
