//
//  위장.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/13.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map;
    
    for(int i=0; i < clothes.size(); i++){
        map[clothes[i][1]] += 1;
    }
    
    for(auto it = map.begin(); it != map.end(); it++){
        answer *= it->second + 1;
    }
    
    return answer-1;
}

int main(){
    cout<<solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}});
    
    return 0;
}
