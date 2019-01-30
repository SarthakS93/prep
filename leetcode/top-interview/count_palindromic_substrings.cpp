#include<iostream>
using namespace std;

int length(char* s) {
    if (s[0] == '\0')
        return 0;
    else 
        return 1 + length(s + 1);
}

int countPS(char* s, int start, int end) {
    if (start == end) {
        return 0;
    }
    else if (start + 1 == end) {
        return s[start] == s[end];
    }
    
    int ans = countPS(s, start + 1, end) 
        + countPS(s, start, end - 1) - countPS(s, start + 1, end - 1);
    
    while (start < end) {
        if (s[start] != s[end]) {
            return ans;
        }
        start++;
        end--;
    }

    return ans + 1;
}

int main() {
    
    char s[100];
    cin>>s;
    
    cout<<"Count of palindromic substrings is as follows: "<<countPS(s, 0, length(s) - 1)<<endl;

    return 0;
}
