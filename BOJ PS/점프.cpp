//
//  점프.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/10.
//

#include <iostream>
#include <algorithm>
using namespace std;

long long field[105][105];

void print_ans(int n, int m){
    cout<<"\n==========================\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<field[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\n==========================\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    field[0][0] = 1;
    
    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            long long temp;
            cin>>temp;
            if(temp == 0) continue;
            
            if(i+temp < n) field[i+temp][j] += field[i][j];
            if(j+temp < n) field[i][j+temp] += field[i][j];
//            cout<<"\nI: "<<i<<", J: "<<j<<" INPUT: "<<temp;
//            print_ans(n, n);
        }
        
    }
    
//    print_ans(n, n);
    cout<<field[n-1][n-1];
    return 0;
}
