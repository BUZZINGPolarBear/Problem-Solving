//
//  기술 연계마스터 임스.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/02.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    int ans=0;
    string temp;
    stack<char> lr_energy, sk_energy;
    cin>>n;
    cin>>temp;
    
    int s_cnt=0,l_cnt=0;
    char current_energy='z';
    
    for(int i=0; i<temp.size(); i++){
        char now_at = temp[i];
        if(0 <= now_at-'0' && now_at-'0' <=9){
            ans++;
            continue;
        }
        
        if(now_at=='S') s_cnt++;
        else if(now_at=='L') l_cnt++;
        else if(now_at=='K'){
            if(s_cnt>0){
                ans++;
                s_cnt--;
            }
            else if(s_cnt<=0){
                cout<<ans;
                return 0;
            }
        }
        else if(now_at=='R'){
            if(l_cnt>0){
                ans++;
                l_cnt--;
            }
            else if(l_cnt<=0){
                cout<<ans;
                return 0;
            }
        }
       
    }
    cout<<ans;
    return 0;
}
