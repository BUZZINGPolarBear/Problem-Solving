//
//  2xn 타일링.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/12.
//

#include <iostream>
#include <string>
#include <vector>
#define BIGINT 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(8);
    
    if(n<5) return v[n];
    else{
        for(int i=6; i<=n; i++){
            v.push_back((v[i-2] + v[i-1])%BIGINT);
        }
    }
    return v[n];
}
