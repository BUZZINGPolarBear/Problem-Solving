//
//  1, 2, 3 더하기 2.cpp
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
vector<int> v;
bool is_end = false;


void back_tracking(int sum, int n, int k){
    if(sum > n) return;
    else if(sum == n){
        ans++;
        if(ans == k){
            cout<<v[0];
            for(int i=1; i<v.size(); i++){
                cout<<"+"<<v[i];
            }
            is_end = true;
        }
        return;
    }
    else {
        for(int i=1; i<=3; i++){
            v.push_back(i);
            back_tracking(sum+i, n, k);
            v.pop_back();
        }
    }
}

void solve(){
    int n, k;
    
    cin>>n>>k;
    
    back_tracking(0, n, k);
    
    if(is_end == false){
        cout<<-1;
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}

