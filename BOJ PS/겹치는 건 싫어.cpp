//
//  겹치는 건 싫어.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int field[100100];
vector<int> inpt_v;
int n, k;
int ans = -1000;

void print_field(int from, int to){
    cout<<"\n------------------------\n";
    for(int i=from; i<=to; i++){
        cout<<field[i]<<" ";
    }
}

void input(){
    cin>>n>>k;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        
        inpt_v.push_back(temp);
    }
}

void find_ans(){
    int left = 0;
    int right = 0;
    
//    field[inpt_v[0]] += 1;
    while(left <= right && right < n){
        int now_idx = inpt_v[right];
        
        if(field[now_idx] < k){
            field[now_idx]++;
            right++;
            ans = max(ans, right-left);
        }
        else{
            field[inpt_v[left++]]--;
            ans = max(ans, right-left);
        }
//        print_field(1, 7);
    }
    
    cout<<ans;
}

void solve(){
    input();
    find_ans();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
