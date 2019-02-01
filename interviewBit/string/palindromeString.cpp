#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s) {
    bool isPalindrome = true;
    int low = 0, high = s.size() - 1;
    
    while (low < high) {
        if (!isalnum(s[low])) {
            low++;
        }
        else if (!isalnum(s[high])) {
            high--;
        }
        else {
           char a = tolower(s[low]), b = tolower(s[high]);
           if (a != b) {
                return false;
           }
           low++;
           high--;
        }
    }
    
    return isPalindrome;
}

int main() {

    string s = "";
    
    cout<<isPalindrome(s)<<endl;

    return 0;
}
