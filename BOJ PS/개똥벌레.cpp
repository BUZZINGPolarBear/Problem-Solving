//
//  개똥벌레.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

pair<int, int> ans;
int n, h;
int bottom_cave[500001]={0, }, top_cave[500001]={0, };

void input(){
    cin>>n>>h;
    
    for(int i=0; i<n/2; i++){
        int bot, top;
        cin>>bot>>top;
        
        bottom_cave[bot] += 1;
        top_cave[h+1-top] += 1;
    }
}

void print_cave(){
    cout<<"BOTTOM : ";
    for(int i=1; i<=h; i++)cout<<bottom_cave[i]<<" ";
    cout<<"\nTOP: ";
    for(int i=1; i<=h; i++)cout<<top_cave[i]<<" ";
    cout<<"\n----------------\n";
}

void make_accumulate_sum(){
    for(int i=1; i<=h; i++){
        top_cave[i] += top_cave[i-1];
        bottom_cave[h-i] += bottom_cave[h-i+1];
    }
}

void find_ans(){
    int min = 987654321;
    
    for(int i=1; i<=h; i++){
        int cnt = bottom_cave[i] + top_cave[i];
        
//        cout<<"\n현재 높이: "<<i<<", 파괴 갯수: "<<cnt;
        
        if(cnt < min){
            ans.first = cnt;
            ans.second = 1;
            min = cnt;
        }
        else if(cnt == min){
            ans.second += 1;
        }
    }
    return;
}

void solve(){
    input();
    make_accumulate_sum();
//    print_cave();
    find_ans();
    
    cout<<ans.first<<" "<<ans.second;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
