#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int amazingSubarrays(string s) {
    unordered_set<char> vowels; 
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('A');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('E');
    vowels.insert('U');
    long long int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (vowels.find(s[i]) != vowels.end()) {
            ans += s.size() - i;
            ans = ans % 10003;
        }
    }
    return (int) ans;
}

int main() {
    
    string s;
    cin>>s;

    cout<<amazingSubarrays(s)<<endl;

    return 0;
}
