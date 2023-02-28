//
//  최댓값과 최솟값.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/10.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    s += ' ';
    while(s.size()){
        v.push_back(stoi(s.substr(0, s.find(' '))));
        
        s = s.substr(s.find(' ')+1);
    }
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]);
    answer += ' ';
    answer += to_string(v[v.size()-1]);
    
    return answer;
}

int main(){
    cout << solution("1 2 3 4");
    
    return 0;
}
