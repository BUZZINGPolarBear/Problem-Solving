//
//  귀여운 라이언.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long field[10000010];
long long ans = 10000010;
int n, k;

void input(){
    cin>>n>>k;
    
    for(int i=0; i<n; i++){
        cin>>field[i];
    }
}

void find_ans(){
    long long left = 0;
    long long right = 0;
    int local_k = 0;
    
    if(field[0] == 1) local_k++;
    while(left<=right && right < n){
        if(local_k >= k){
            ans = min(ans, (right-left)+1);
            
            if(field[left] == 1) local_k--;
            left++;
        }
        else{
            right++;
            if(field[right] == 1)local_k++;
        }
    }
    
    if(ans == 10000010) cout<<-1;
    else cout<<ans;
}
void solve(){
    input();
    find_ans();
    
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    
    return 0;
}
