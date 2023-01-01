//
//  물병.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/31.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;

int main(){
    using namespace std;
    int n, k;
    int ans = 987654321;
    bitset<30> bitset;
    
    cin>>n>>k;
    
    if(n<=k){
        cout<<0;
        return 0;
    }
    
    int result =0;
    for(result =0; ;result++){
        int cnt=0;
        int tempN = n;
        
        while(tempN){
            if(tempN%2){
                cnt++;
            }
            tempN /= 2;
        }
        
        if(cnt<=k) break;
        n++;
    }
    cout<<result;
    return 0;
}
