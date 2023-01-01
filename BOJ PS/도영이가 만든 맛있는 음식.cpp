//
//  도영이가 만든 맛있는 음식.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    vector<int> sour_v, bitter_v;
    
    cin>>n;
    for(int i=0; i<n; i++){
        int sour, bitter;
        cin>>sour>>bitter;
        
        sour_v.push_back(sour);
        bitter_v.push_back(bitter);
    }
    
    int sour;
    int bitter;
    int ans = 987654321;
    
    for(int i = 1; i <= (1<<n)-1; i++){
        sour = 1;
        bitter = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                //i집합에서 j번째 음식이 선택된 경우
                sour *= sour_v[j];
                bitter += bitter_v[j];
            }
        }
        ans = min(ans, abs(sour - bitter));
    }
    
    cout<<ans;
    return 0;
}
