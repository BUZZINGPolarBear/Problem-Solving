//
//  전구와 스위치.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/19.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    
    cin>>n;
    vector<bool> origin_v(n), objective_v(n);
    string temp1_str, temp2_str;
    cin>>temp1_str>>temp2_str;
    for(int i=0; i<n; i++) {
        if(temp1_str[i] == '0') origin_v[i] = 0;
        else origin_v[i] = 1;
    }
    for(int i=0; i<n; i++) {
        if(temp2_str[i] == '0') objective_v[i] = 0;
        else objective_v[i] = 1;
    }
    
    int start_with_zero = 0, start_with_one = 0;
    
    vector<bool> temp_1_v = origin_v;
    for(int i=1; i<n; i++){
        //0번째 전구를 안누르고 시작
        if(objective_v[i-1] != temp_1_v[i-1]){
            start_with_zero++;
            temp_1_v[i-1] = !temp_1_v[i-1];
            temp_1_v[i] = !temp_1_v[i];
            temp_1_v[i+1] = !temp_1_v[i+1];
        }
    }
    
    vector<bool> temp_2_v = origin_v;
    temp_2_v[0] = !temp_2_v[0];
    temp_2_v[1] = !temp_2_v[1];
    start_with_one++;
    for(int i=1; i<n; i++){
        //0번째 전구를 누르고 시작
        if(objective_v[i-1] != temp_2_v[i-1]){
            start_with_one++;
            temp_2_v[i-1] = !temp_2_v[i-1];
            temp_2_v[i] = !temp_2_v[i];
            temp_2_v[i+1] = !temp_2_v[i+1];
        }
    }
    
    for(int i=0; i<n; i++){
        if(temp_1_v[i] != objective_v[i]) start_with_zero = 987654321;
        if(temp_2_v[i] != objective_v[i]) start_with_one = 987654321;
    }
    
    if(start_with_one==987654321 && start_with_zero == 987654321) cout<<-1;
    else cout<<min(start_with_zero, start_with_one);
    return 0;
}
