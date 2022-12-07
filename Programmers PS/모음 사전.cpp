//
//  모음 사전.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/07.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> voca;
int cnt = 1;
vector<string> alpha = {"A", "E", "I", "O", "U"};

void dfs(string str){
    if(str.length() > 5) return;
    voca[str] = cnt++;
    for(auto i : alpha) dfs(str + i);
}

int solution(string word) {
    for(auto s : alpha) dfs(s);
    int temp = 0;
    
    return voca[word];
}

int main(){
    cout<<solution("AAAAE");
    
    return 0;
}
