//
//  구간 합 구하기 5.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/24.
//

#include <iostream>
using namespace std;

int field[1030][1030], sum[1030][1030];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            field[i][j] = temp;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + field[i-1][j-1];
        }
    }
    
    
    for(int i=0; i<m; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        x2--;
        y1--;
        y2--;
        cout<<sum[x2+1][y2+1] - sum[x1][y2+1] - sum[x2+1][y1] + sum[x1][y1]<<"\n";
    }
    
}
