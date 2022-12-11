//
//  나는야 포켓몬 마스터 이다솜.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/10.
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    unordered_map<int, string> map_int_string;
    unordered_map<string, int> map_string_int;
    
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        string temp;
        cin>>temp;
        
        map_int_string.insert({i, temp});
        map_string_int.insert({temp, i});
    }
    
    for(int i=0; i<m; i++){
        string temp;
        cin>>temp;
        
        if(isdigit(temp[0])){
            int to_num = stoi(temp);
            cout<<map_int_string[to_num]<<"\n";
        }
        else{
            cout<<map_string_int[temp]<<"\n";
        }
    }
    return 0;
}
