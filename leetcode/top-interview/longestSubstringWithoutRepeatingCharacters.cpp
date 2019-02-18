#include<iostream>
#include<string>
using namespace std;

bool isBadChar(int i, int j, int bucketPos) {
    cout<<"BucketPos "<<bucketPos<<endl;
    if (bucketPos >= i && bucketPos < j) {
        return true;
    }
    else {
        return false;
    }
}

string longstSubstringWithoutRepeatChar(string s) {
    int i = 0, j = 0, n = s.size();
    int bucket[256], maxLength = 0, maxStartIndex = 0;
    for (int k = 0; k < 256; k++) {
        bucket[k] = -1;
    }
    for (j = 0; j < n; j++) {
        int charCode = s[j];
        //cout<<charCode<<endl;
        cout<<"i "<<i<<", j"<<j<<endl;
        if (isBadChar(i, j, bucket[charCode])) {
            cout<<s[j]<<" is bad char"<<endl;
            int curLength = j - i;
            cout<<"Current Length: "<<curLength<<" and Max Length: "<<maxLength<<endl;
            i = bucket[s[j]] + 1;
        }
        else {
            int curLength = j - i + 1;
            if (curLength > maxLength) {
                maxLength = curLength;
            }
        }
        bucket[s[j]] = j;
    }

    cout<<"Max length "<<maxLength<<" and maxStartIndex "<<maxStartIndex<<endl;

    return s.substr(maxStartIndex, maxLength);
}

int main() {

    string s;
    cin>>s;
    
    cout<<longstSubstringWithoutRepeatChar(s)<<endl;

    return 0;
}
