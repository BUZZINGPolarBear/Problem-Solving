//
//  쉽게 푸는 문제.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/07.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long ans = 0;
    vector<int> v;
    int a, b;
    cin>>a>>b;
    
    for(int i=1; i<=1000; i++){
        for(int j=0; j<i; j++) {
            v.push_back(i);
        }
        if(v.size() >1000) break;
    }
    
    for(int i=a-1; i<b; i++) {
        ans += v[i];
    }
    
    cout<<ans;
    return 0;
}
