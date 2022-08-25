//
//  x만큼 간격이 있는 n개의 숫자.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i=1; i<=n; i++){
        answer.push_back(x * i);
    }
    return answer;
}
