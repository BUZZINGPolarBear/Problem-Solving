//
//  [1차] 다트 게임.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    long long total_score = 0;
    int old_score = 0;
    int new_score = 0;
    for(int i=0; i<dartResult.size(); i){
        string temp_stoi="";

        if(dartResult[i]=='1' && dartResult[i+1]=='0') {
            new_score = 10;
            i+=2;
        }
        else {
            new_score = dartResult[i] - '0';
            i++;
        }
        if(dartResult[i] == 'S'){
            i++;
        }
        else if(dartResult[i] == 'D'){
            new_score = new_score * new_score;
            i++;
        }
        else if(dartResult[i] == 'T'){
            new_score = new_score * new_score * new_score;
            i++;
        }
        if(dartResult[i] == '#') {
            i++;
            new_score *= -1;
        }
        if(dartResult[i] == '*') {
            i++;
            total_score -= old_score;
            total_score += new_score*2 + old_score*2;
            old_score = new_score*2;
            continue;
        }
        total_score += new_score;
        old_score = new_score;
        new_score = 0;
    }
    return total_score;
}

int main(){
    cout<<solution("1D2S3T*");
    return 0;
}
