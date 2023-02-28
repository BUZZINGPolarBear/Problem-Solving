//
//  키로거.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/18.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <deque>
using namespace std;
int n;

void solve(){
    cin>>n;
    while(n--){
        string temp;
        string ans="";
        int cursor = 0;
        cin>>temp;
        deque<char> left_dq, right_dq;
        
        for(int i=0; i<temp.size(); i++){
            if(temp[i] == '<'){
                if(!left_dq.empty()){
                    right_dq.push_front(left_dq.back());
                    left_dq.pop_back();
                }
                
            }
            else if(temp[i] == '>'){
                if(!right_dq.empty()){
                    left_dq.push_back(right_dq.front());
                    right_dq.pop_front();
                }
            }
            else if(temp[i] == '-'){
                if(!left_dq.empty()){
                    left_dq.pop_back();
                }
            }
            else{
                left_dq.push_back(temp[i]);
            }
        }
        
        while(!left_dq.empty()){
            cout<<left_dq.front();
            left_dq.pop_front();
        }
        while(!right_dq.empty()){
            cout<<right_dq.front();
            right_dq.pop_front();
        }
        cout<<"\n";
       
    }
}

int main(){
    using namespace std;
    cin.tie(0);
    cout.tie(0);
    
    solve();
}
