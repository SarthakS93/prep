#include<iostream>
using namespace std;

bool getIsDistributionPossible(int arr[], int index, int size, int sum) {
    if (index >= size || sum < 0) {
        return false;
    }
    else if (sum == 0) {
        return true;
    }
    else {
        return 
            (getIsDistributionPossible(arr, index + 1, size, sum - arr[index])
            || getIsDistributionPossible(arr, index + 1, size, sum));
    }
}

bool getIsDistributionPossibleDP(int arr[], int size, int sum) {
    bool dp[size + 1][sum + 1];

    for (int i = 0; i <= size; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
      dp[0][i] = false;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= sum; j++) {
            
            if(j < arr[i-1]) {
                dp[i][j] = dp[i - 1][j];
            }
            
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }

        }
    }

    return dp[size][sum];
}

int main() {

    int t, arr[10005], dp[10005];
    cin>>t;
    while (t--) {
        int n, x;
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        cin>>x;

        for (int i = 0; i < n + 1; i++)
            dp[i] = 0;

        //bool isPossible = getIsDistributionPossible(arr, 0, n, x);
        bool isPossible = getIsDistributionPossibleDP(arr, n, x);
        
        if (isPossible) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
