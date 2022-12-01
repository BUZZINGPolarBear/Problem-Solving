//
//  탑.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/26.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    stack<pair<int, int> > st;
    
    int n;
    cin>>n;
    
    int temp;
    cin>>temp;
    
    st.push({temp, 1});
    cout<<"0 ";
    for(int i=2; i<=n; i++){
        cin>>temp;
        if(st.top().first < temp){
            while(!st.empty()){
                if(st.top().first >= temp)
                {
                    cout<<st.top().second<<" ";
                    break;
                }
                st.pop();
            }
            if(st.empty()) cout<<"0 ";
            st.push({temp, i});
            
        }
        
        else{
            cout<<st.top().second<<" ";
            st.push({temp, i});
        }
    }
}
