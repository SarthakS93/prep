#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


void nextGreaterElement(vector<int> v) {
    stack<int> s;
    s.push(v[0]);
    
    for (int i = 1; i < v.size(); i++) {
        
        if (s.empty()) {
            s.push(v[i]);
            continue;
        }

        while (!s.empty() && v[i] > s.top()) {
            cout<<s.top()<<" -- "<<v[i]<<endl;
            s.pop();
        }

        s.push(v[i]);
    }

    while (!s.empty()) {
        cout<<s.top()<<" -- "<<-1<<endl;
        s.pop();
    }

}

vector<int> nextGreaterElementIndex(vector<int> v, bool isLeft) {
    stack<int> s;
    vector<int> res(v.size(), 0);
    
    if (!isLeft) {
        for (int i = 0; i < v.size(); i++) {
            while (!s.empty() && v[i] > v[s.top() - 1]) {
                int poppedElement = s.top();
                s.pop();

                res[poppedElement - 1] = i + 1;
            }
            
            s.push(i + 1);
        }
    }
    else {
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!s.empty() && v[i] > v[s.top() - 1]) {
                int poppedElement = s.top();
                s.pop();
                res[poppedElement - 1] = i + 1;
            }
            s.push(i + 1);
        }
    }
    
    return res;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int maxSpecialProduct(const vector<int> &A) {
    vector<int> v(A);
    vector<int> left = nextGreaterElementIndex(v, true);
    vector<int> right = nextGreaterElementIndex(v, false);

    print(left);
    print(right);

    long long int ans = -1;
    for (int i = 0; i < left.size(); i++) {
        long long int prod = left[i] * right[i];
        ans = max(ans, prod);
    }
    
    return ans;
}

int main() {

    vector<int> v;
    v.push_back(5);
    v.push_back(9);
    v.push_back(6);
    v.push_back(8);
    v.push_back(6);
    v.push_back(4);
    v.push_back(6);
    v.push_back(9);
    v.push_back(5);
    v.push_back(4);
    v.push_back(9);

    cout<<maxSpecialProduct(v)<<endl;
    
    //nextGreaterElement(v);

    return 0;
}
