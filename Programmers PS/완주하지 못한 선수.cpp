//
//  완주하지 못한 선수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/12.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size(); i++){
        if(participant[i] != completion[i]) return participant[i];
    }
    return participant[participant.size()];
}

int main(){
    vector<string> participant={"mislav", "stanko", "mislav", "ana"}, completion = {"stanko", "ana", "mislav"};
    
    cout<<solution(participant, completion);
    return 0;
}


