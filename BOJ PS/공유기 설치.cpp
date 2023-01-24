//
//  공유기 설치.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

void input(){
    cin>>n>>c;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
}

void solve(){
    input();
    
    int start = 1;
    int end = v[n-1] - v[0];
    int result = 0;
    
    while(start <= end){
        int mid = (start + end)/2;
        
        int cnt = 1;
        int prev_house = v[0];
        for(int i=1; i<n; i++){
            if(v[i] - prev_house >= mid){
                cnt++;
                prev_house = v[i];
            }
        }
        
        if(cnt >= c){
            result = max(result, mid);
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    
    cout<<result;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
