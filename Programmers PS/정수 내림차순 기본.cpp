//
//  정수 내림차순 기본.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    
    sort(v.rbegin(), v.rend());
    
    for(int i=0; i<v.size(); i++){
        answer += v[i] * pow(10, v.size()-i-1);
    }
    return answer;
}

int main(){
    cout<<solution(118372);
    return 0;
}
