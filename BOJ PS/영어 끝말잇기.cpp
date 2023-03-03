//
//  영어 끝말잇기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/21.
//

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> word_set;
    
    int round = 1;
    bool is_end = 0;
    word_set.insert(words[0]);
    
    for(int i=1; i<words.size(); i++){
        if(i%n == 0) round+=1;
        
        string now_str = words[i];
        string before_str = words[i-1];
        
        if(now_str[0] != before_str[befor_str.size()-1]){
            answer.push_back((i+1)%n);
            answer.push_back(round);
            break;
        }
        
        if(word_set.find(now_str) == word_set.end()){
            word_set.insert(now_str);
        }
        else{
            answer.push_back((i+1)%n);
            answer.push_back(round);
            break;
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
