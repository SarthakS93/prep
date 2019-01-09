#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int> & v) {
    int low = 0, high = v.size() - 1, i = - 1, j = 0;

    int pivot = v[high];

    for (j = low; j < high - 1; j++) {

        if (v[j] <= pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }

    }

    int temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;

    return i + 1;
}

void swap(vector<int> &v, int x, int y) {
    cout<<"Before swap "<<v[x]<<" and "<<v[y]<<endl;
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
    cout<<"After swap "<<v[x]<<" and "<<v[y]<<endl;
}

vector<int> sortByParity(vector<int> v) {
    vector<int> a;
    for (int i = 0; i < v.size(); i++) {
        a.push_back(v[i]);
    }
    
    int low = 0, high = a.size() - 1;
    while (low < high) {
        if (a[low] % 2 != 0 && a[high] % 2 == 0) {
            swap(a, low, high);
            low++;
            high--;
        }
        else if (a[low] % 2 == 0) {
            low++;
        }
        else if (a[high] % 2 != 0) {
            high--;
        }
    }
    return a;
}


int main() {

    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<int> a = sortByParity(v);

    for (int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}
