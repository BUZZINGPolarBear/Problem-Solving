//
//  귤 고르기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/25.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define max 100005

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> map;
    for(auto i:tangerine){
        map[i] += 1;
    }
    
    vector<int> v;
    
    for(auto i = map.begin(); i!=map.end(); i++) v.push_back(i->second);
    sort(v.begin(), v.end());
    
    int sum_size = 0, cnt=0, size=v.size();
        
    for(int i=0; i<size; i++){
        sum_size += v[i];
        answer++;
    }
    
    for(int i=0; i<size; i++){
        if(sum_size - v[i] < k) break;
        answer--;
        sum_size -= v[i];
    }
    
    return answer;
}

int main(){
    cout<<solution(4, {1, 3, 2, 5, 4, 5, 2, 3});
    
    return 0;
}
