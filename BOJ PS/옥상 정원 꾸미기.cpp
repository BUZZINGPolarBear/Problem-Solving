//
//  옥상 정원 꾸미기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/27.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, ans=0;
    cin>>n;
    vector<long long > v(n);
    stack<pair<long long , long long > > st;
    
    for(long long i=0; i<n; i++) {
        cin>>v[i];
    }
    
    st.push({v[n-1], 0});
    for(long long i=n-2; i>=0; i--){
        long long height = v[i];
        
        if(!st.empty()){
            if(st.top().first >= height){
                st.push({height, 0});
                continue;
            }
            else{
                long long temp=0;
                while(st.top().first < height){
                    temp++;
                    temp += st.top().second;
                    st.pop();
                    if(st.empty()) break;
                }
                st.push({height, temp});
                ans += temp;
            }
        }
    }
    cout<<ans;
    return 0;
}
