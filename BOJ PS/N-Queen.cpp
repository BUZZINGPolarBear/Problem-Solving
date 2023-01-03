//
//  N-Queen.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/02.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
int board[20][20];
int ans=0;

void go(int cnt){
    if(cnt==n){
        ans++;
        return;
    }
    
    for(int i=0; i<n; i++){
        if(board[cnt][i]==0){
            //퀸을 둘 수 있는 상황
            for(int k=1; k<n; k++){
                //아래
                if(cnt + k < n) board[cnt + k][i]++;
                //오른쪽 아래 대각선
                if(cnt + k < n && i + k < n) board[cnt+k][i+k]++;
                //왼쪽 아래 대각선
                if(cnt + k < n && i - k >=0) board[cnt+k][i-k]++;
            }
            go(cnt+1);
            
            //백트래킹
            for(int k=1; k<n; k++){
                //아래
                if(cnt + k < n) board[cnt + k][i]--;
                //오른쪽 아래 대각선
                if(cnt + k < n && i + k < n) board[cnt+k][i+k]--;
                //왼쪽 아래 대각선
                if(cnt + k < n && i - k >=0) board[cnt+k][i-k]--;
            }
        }
    }
    return;
    
}
int main(){
    cin>>n;
    
    go(0);
    cout<<ans;
    return 0;
}
