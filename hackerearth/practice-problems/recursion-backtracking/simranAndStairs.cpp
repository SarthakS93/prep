#include<iostream>
using namespace std;

int numberOfSteps(int n, int dp[]) {
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        return 0;
    }
    else {
        if (dp[n] != -1) {
            return dp[n];
        }
        else {
            int ways = numberOfSteps(n - 1, dp) + numberOfSteps(n - 2, dp) + numberOfSteps(n - 3, dp);
            dp[n] = ways;
            return ways;
        }
    }
}


int main() {

    int n;
    cin>>n;
    int dp[31];
    for (int i = 0; i < 31; i++)
        dp[i] = -1;
    dp[0] = 0;
    cout<<numberOfSteps(n, dp)<<endl;

    return 0;
}
