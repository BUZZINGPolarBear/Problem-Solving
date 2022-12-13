//
//  도키도키 간식드리미.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/12.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    queue<int> q;
    stack<int> st;
    int n, next=1;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    
    while(!q.empty()){
        if(q.front() != next){
            if(st.empty() == false && st.top() == next){
                st.pop();
                next++;
            }
            else if(st.empty() == false && st.top() != next){
                st.push(q.front());
                q.pop();
            }
            if(st.empty()){
                st.push(q.front());
                q.pop();
            }
        }
        else{
            q.pop();
            next++;
        }
    }
    
    while(!st.empty()){
        if(st.top() == next){
            st.pop();
            next++;
        }
        else{
            cout<<"Sad";
            return 0;
        }
    }
    cout<<"Nice";
    return 0;
    
}
