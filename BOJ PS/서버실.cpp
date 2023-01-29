//
//  서버실.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/28.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

unsigned long long total;
unsigned long long n;
unsigned long long field[1005][1005];
unsigned long long max_inpt;
void input(){
    cin>>n;
    
    for(unsigned long long i=0; i<n; i++){
        for(unsigned long long j=0; j<n; j++){
            unsigned long long temp;
            cin>>temp;
            
            total += temp;
            field[i][j] = temp;
            max_inpt = max(max_inpt, temp);
        }
    }
}

void find_ans(){
    unsigned long long left = 0;
    unsigned long long right = max_inpt;
    unsigned long long ans = 10001000;
    
    while(left+1<right){
        unsigned long long mid = (left+right)/2;
        unsigned long long cnt = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cnt += mid > field[i][j] ? field[i][j] : mid;
            }
        }
        
        if(((double)cnt/total) >= 0.5){
            ans = min(ans, mid);
//            cout<<"Left: "<<left<<" Right: " << right<<" 컴퓨터: "<<cnt<<"\n---------------\n";
            right = mid;
        }
        else{
            left = mid;
        }
    }
    
    cout<<right;
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


