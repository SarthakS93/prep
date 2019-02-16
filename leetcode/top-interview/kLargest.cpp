#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);

    for (int i = 0; i < k - 1; i++)
        pq.pop();

    return pq.top();
}

int main() {
    
    int n, k;
    cin>>n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin>>v[i];

    cin>>k;

    cout<<findKthLargest(v, k)<<endl;

    return 0;
}
