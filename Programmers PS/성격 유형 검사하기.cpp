//
//  성격 유형 검사하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/01.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> map;
    map.insert({'R', 0});
    map.insert({'T', 0});
    map.insert({'C', 0});
    map.insert({'F', 0});
    map.insert({'J', 0});
    map.insert({'M', 0});
    map.insert({'A', 0});
    map.insert({'N', 0});
    
    for(int i=0; i<survey.size(); i++){
        char first = survey[i][0];
        char second = survey[i][1];
        
        switch (choices[i]) {
            case 1:
                map[first] += 3;
                break;
            case 2:
                map[first] += 2;
                break;
            case 3:
                map[first] += 1;
                break;
            case 4:
                break;
            case 5:
                map[second] += 1;
                break;
            case 6:
                map[second] += 2;
                break;
            case 7:
                map[second] += 3;
                break;
        }
    }
    
    for(int i=0; i<4; i++){
        switch (i) {
            case 0:
                if(map['R'] < map['T']) answer += "T";
                else if(map['R'] > map['T']) answer += "R";
                else if (map['R'] == map['T']) answer += "R";
                break;
                
            case 1:
                if(map['C'] < map['F']) answer += "F";
                else if(map['C'] > map['F']) answer += "C";
                else if (map['C'] == map['F']) answer += "C";
                break;
                
            case 2:
                if(map['J'] < map['M']) answer += "M";
                else if(map['J'] > map['M']) answer += "J";
                else if (map['J'] == map['M']) answer += "J";
                break;
                
            case 3:
                if(map['A'] < map['N']) answer += "N";
                else if(map['A'] > map['N']) answer += "A";
                else if (map['A'] == map['N']) answer += "A";
                break;
                
            default:
                break;
        }
    }
    
    
    return answer;
}

int main()
{
    cout<<solution({"AN", "CF", "MJ", "RT", "NA"}, {5, 3, 2, 7, 5});
    return 0;
}
