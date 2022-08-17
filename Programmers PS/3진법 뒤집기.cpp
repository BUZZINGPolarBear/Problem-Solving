//
//  3진법 뒤집기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/17.
//
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int upper = 0;
    vector<int> v;
    
    while(n){
        v.push_back(n%3);
        n /= 3;
    }
    
    for(int i=v.size()-1; i>=0; i--){
        if(upper == 0){
            answer += v[i];
        }
        else{
            answer += pow(3, upper) * v[i];
        }
        upper++;
    }
    
    return answer;
}

int main()
{
    cout<<solution(125);
    return 0;
}
