//
//  비밀번호 발음하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/26.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(string input){
    bool first_check = false;
    for(int i=0; i<input.size(); i++){
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            first_check = true;
        }
        
        if(i>=1){
            if(input[i] == input[i-1]){
                string temp = input.substr(i-1, 2);
                if(temp != "ee" && temp != "oo"){
//                    cout<<"SAME!! : "<<temp<<endl;
                    return 0;
                }
            }
        }
    }
    
    bool second_check = false;
    int moum_cnt = 0;
    int jaum_cnt = 0;
    for(int i=0; i<input.size(); i++){
        if(moum_cnt >= 3||jaum_cnt >= 3) return 0;
        else{
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
                if(moum_cnt >= 0){
                    moum_cnt++;
                    jaum_cnt = 0;
                    continue;
                }
                else if(jaum_cnt>0){
                    jaum_cnt = 0;
                    moum_cnt = 1;
                }
            }
            else{
                if(jaum_cnt >= 0){
                    jaum_cnt++;
                    moum_cnt = 0;
                    continue;
                }
                else if(moum_cnt>0){
                    moum_cnt = 0;
                    jaum_cnt = 1;
                }
            }
        }
    }
    if(moum_cnt == 3 || jaum_cnt == 3) return 0;
    if(first_check == false) return 0;
    else return 1;
}

void solve(){
    while(1){
        string input;
        cin>>input;
        
        if(input == "end") break;
        
        bool is_acceptable = check(input);
        
        if(is_acceptable) cout<<"<"<<input<<"> is acceptable.\n";
        else cout<<"<"<<input<<"> is not acceptable.\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
