//
//  명령 프롬프트.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/08.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    string ans = "";
    cin>>n;
    vector<string> v(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    if(n==1){
        cout<<v[0];
        return 0;
    }
    
    for(int i=0; i<v[0].size(); i++){
        int is_same = 1;
        char temp = v[0][i];
        
        for(int j=1; j<n; j++){
            if(v[j][i] != temp) is_same = 0;
        }
        
        if(is_same) ans += temp;
        else ans += "?";
    }
    
    cout<<ans;
    return 0;
}
