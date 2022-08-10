//
//  숫자 문자열과 영단어.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string str_answer = "";
    int answer = 0;
    map<string, string> sToi_map;
    sToi_map["zero"] = "0";
    sToi_map["one"] = "1";
    sToi_map["two"] = "2";
    sToi_map["three"] = "3";
    sToi_map["four"] = "4";
    sToi_map["five"] = "5";
    sToi_map["six"] = "6";
    sToi_map["seven"] = "7";
    sToi_map["eight"] = "8";
    sToi_map["nine"] = "9";
    
    while(1){
        bool is_english_found = false;
        for(auto i:sToi_map){
            
            if(s.find(i.first)!=string::npos){
                s.replace(s.find(i.first), i.first.size(), sToi_map[i.first]);
                is_english_found = true;
            }
            
        }
        if(is_english_found == false) break;
    }
    answer =stoi(s);
    

    return answer;
}

int main()
{
    string test = "one4seveneight";
    cout<< solution(test);
    
    return 0;
}
