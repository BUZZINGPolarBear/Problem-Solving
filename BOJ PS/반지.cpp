//
//  반지.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/07.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string base;
    int n;
    int ans=0;
    cin>>base>>n;
    
    for(int i=0; i<n; i++){
        string temp;
        queue<char> q;
        
        cin>>temp;
        
        temp += temp;
        temp += temp;
        temp += temp;
        temp += temp;
        for(int j=0; j<temp.size(); j++){
            if(temp[j] == base[0]){
                if(temp.substr(j, base.size()) == base){
                    ans++;
                    break;
                }
            }
        }
        
        
    }
    cout<<ans;
    return 0;
}
