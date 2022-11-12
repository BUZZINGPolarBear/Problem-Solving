//
//  롤케이크 자르기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/07.
//

#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_set<int> a_set, b_set;
    map<int, int> map;
    
    map[topping[0]] = 1;
    
    for(int i=1; i<topping.size(); i++){
        b_set.insert(topping[i]);
        map[topping[i]] +=1;
    }
    
    for(int i=0; i<topping.size(); i++){
        if(a_set.size() == b_set.size()) answer++;
        if(map[topping[i]] >0){
            map[topping[i]] -= 1;
            a_set.insert(topping[i]);
            
        }
        if(map[topping[i]] <= 0){
            b_set.erase(topping[i]);
            a_set.insert(topping[i]);
        }
    }
    return answer;
}

int main(){
    cout<<solution({1, 2, 1, 3, 1, 4, 1, 2});
    return 0;
}
