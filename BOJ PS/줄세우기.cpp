//
//  줄세우기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs[205][205];

void print_array(int n, int m){
    cout<<"\n==========================\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\n==========================\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    
    for(int i=2; i<=n+1; i++){
        cin>>lcs[i][0];
        lcs[0][i] = i-1;
    }
    
    for(int i=2; i<=n+2; i++){
        for(int j=2; j<=n+2; j++){
            if(lcs[i][0] == lcs[0][j]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    
    //print_array(n+2, n+2);
    cout<<n - lcs[n+1][n+1];
    
    return 0;
}
