//
//  리모컨.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/11.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, temp_n;
    int m;
    int field[10]={0, };
    
    cin>>temp_n>>m;
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        
        field[temp] = 1;
    }
    
    if(temp_n==100){
        //예외처리
        cout<<0;
        return 0;
    }
    if(m==0){
        int ans;
        to_string(temp_n).size() < abs(100-temp_n) ? ans = to_string(temp_n).size() : ans = abs(100-temp_n);
        cout<<ans;
        return 0;
    }
    if(m==10){
        cout<<abs(100-temp_n);
        return 0;
    }
    
    n=temp_n;
    int down_cnt = 0;
    while(1){
        //n부터 하강
        if(n<0){
            down_cnt = -1000;
            break;
        }
        auto to_str = to_string(n);
        bool is_impossible = 0;
        for(int i=0; i<to_str.size(); i++){
            if( field[(to_str[i]) - '0'] == 1) {
                is_impossible = 1;
                break;
            }
        }
        
        if(is_impossible==0){
            down_cnt += to_string(n).size();
            break;
        }
        else{
            n--;
            down_cnt++;
        }
    }
    
    n = temp_n;
    int up_cnt = 0;
    while(1){
        //n부터 상승
        if(up_cnt > down_cnt && down_cnt != -1000) break;
        auto to_str = to_string(n);
        bool is_impossible = 0;
        for(int i=0; i<to_str.size(); i++){
            if( field[(to_str[i]) - '0'] == 1) {
                is_impossible = 1;
                break;
            }
        }
        
        if(is_impossible==0){
            up_cnt += to_string(n).size();
            break;
        }
        else{
            n++;
            up_cnt++;
        }
    }
    if(down_cnt != -1000) cout<<min(up_cnt, min(down_cnt, abs(100 - temp_n)));
    else cout<<min(up_cnt, abs(100 - temp_n));
    
    return 0;
}
