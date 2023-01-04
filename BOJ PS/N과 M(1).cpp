//
//  N과 M(1).cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/04.
//

#include <iostream>
#include <vector>
using namespace std;
int n, m;
int ans[10], check[10];

void back_tracking(int idx, int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++)cout<<ans[i]<<" ";
        cout<<"\n";
    }
    
    for(int i=idx+1; i<=n; i++){
        if(check[i]==false){
            check[i] = true;
            ans[cnt] = i;
            back_tracking(i, cnt+1);
            check[i] = false;
        }
    }
    
}

int main(){
    cin>>n>>m;
    back_tracking(0, 0);
}
