//
//  카드 놓기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/03/01.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int n, k;
vector<string> input_v;
vector<string> temp_v;
set<string> ans_set;
vector<int> temp;

void input(){
    cin>>n>>k;
    string temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        
        input_v.push_back(temp);
    }
}


void solve(){
    sort(input_v.begin(), input_v.end());
    
    do{
        string local_concat = "";
        for(int i=0; i<k; i++) local_concat += input_v[i];
        
        ans_set.insert(local_concat);
    }while(next_permutation(input_v.begin(), input_v.end()));
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solve();
    
//    for(auto i = ans_set.begin(); i!=ans_set.end(); i++) cout<<*i<<" ";
//    cout<<"\n";
    cout<<ans_set.size();
    
    return 0;
}
