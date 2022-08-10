//
//  신고결과 받기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/09.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> userMap;
    for(int i=0; i<id_list.size(); i++) userMap[id_list[i]] = i;
    
    map<string, set<string> > reportMap;
    for(auto i : report){
        string first_user = i.substr(0, i.find(" "));
        string second_user = i.substr(i.find(" ")+1);
        
        reportMap[second_user].insert(first_user);
    }
    
    for(auto i : reportMap){
        if(i.second.size() >= k){
            for(auto reportIter : i.second){
                int idx = userMap[reportIter];
                answer[idx] ++;
            }
        }
    }

    
    return answer;
}

int main(){
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;
    
    vector<int> ans = solution(id_list, report, k);
    
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
    return 0;
    
}
