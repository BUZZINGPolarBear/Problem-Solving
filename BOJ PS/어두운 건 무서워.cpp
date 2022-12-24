//
//  어두운 건 무서워.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/24.
//

#include <iostream>
using namespace std;

int field[1005][1005], sum[1005][1005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int r, c, q;
    cin>>r>>c>>q;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>field[i][j];
        }
    }
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + field[i-1][j-1];
        }
    }
    
    for(int i=0; i<q; i++){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        x2--;
        y1--;
        y2--;
        int temp = sum[x2+1][y2+1] - sum[x1][y2+1] - sum[x2+1][y1] + sum[x1][y1];
        cout<<temp/((x2-x1+1)*(y2-y1+1))<<"\n";
    }
}
