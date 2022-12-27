//
//  문서 검색.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/27.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string original, search;
    int ans=0;
    getline(cin, original);
    getline(cin, search);
    
    for(int i=0; i<original.size(); i++){
        if(original.substr(i, search.size()) == search){
            ans++;
            i+=search.size()-1;
        }
    }
    
    cout<<ans;
    return 0;
}
