#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {

    int n, k;
    vector<int> v;
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<unordered_map<int, bool> > mapVector;
    for (int j = 0; j < k; j++) {
        unordered_map<int, bool> mymap;
        mapVector.push_back(mymap);
    }

    for (int i = 0; i < v.size(); i++) {
        
        bool colored = false;
        for (int j = 0; j < k; j++) {
            unordered_map<int, bool> mymap = mapVector[j];
            /*
            unordered_map<int, bool>::iterator it;
            cout<<j<<" Map state"<<endl;
            for (it = mymap.begin(); it != mymap.end(); ++it) {
                cout<<it->first<<" ";
            }
            cout<<endl;
            cout<<"Checking whether "<<v[i]<<" is present in map of "<<j<<endl;
            */
            if (mymap.count(v[i]) == 0) {
                //cout<<"Not Present"<<endl;
                mymap[v[i]] = true;
                colored = true;
                v[i] = j + 1;
                mapVector[j] = mymap;
                break;
            }
        }

        if (!colored) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;


    /*
    vector<unordered_map<int, bool>> mapV;
    for (int i = 0; i < 2; i++) {
        unordered_map<int, bool> mymap;
        mymap[i] = false;
        mapV.push_back(mymap);
    }
    
    unordered_map<int, bool> firstMap = mapV[0], secondMap = mapV[1];

    unordered_map<int, bool>::iterator it;
    it = firstMap.find(0);
    cout<<it->second<<endl;
*/
    return 0;
}
