//
//  1, 2, 3 더하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 0;
int field[3] = {1, 2, 3};

void back_tracking(int sum, int n){
    if(sum > n) return;
    else if(sum == n){
        ans++;
        return;
    }
    else {
        for(int i=1; i<=3; i++){
            back_tracking(sum+i, n);
        }
    }
}

void solve(){
    int t;
    int n;
    
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        back_tracking(0, n);
        cout<<ans<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
