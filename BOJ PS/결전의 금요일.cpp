//
//  결전의 금요일.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/24.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    vector<int> v;
    
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp%7==4){
            cout<<"YES";
            return 0;
        }
        v.push_back(temp%7);
    }
    
    set<int> set1, set2;
    for(int i=0; i<v.size(); i++){
        for(auto j=set1.begin(); j!=set1.end(); j++){
            int temp = (*j+v[i]) % 7;
            set2.insert(temp);
        }
        set1.insert(v[i]%7);
        for(auto k=set2.begin(); k!=set2.end(); k++){
            set1.insert(*k);
        }
        set<int> set2;
    }
    if(set1.find(4) != set1.end())cout<<"YES";
    else cout<<"NO";
    return 0;
}
