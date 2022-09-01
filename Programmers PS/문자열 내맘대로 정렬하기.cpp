//
//  문자열 내맘대로 정렬하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/31.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<string, int> > origin_v;
    vector<pair<char, int> > sorted_v;
    sort(strings.begin(), strings.end());
    
    for(int i=0; i<strings.size(); i++) origin_v.push_back({strings[i], i});
    for(int i=0; i<origin_v.size(); i++){
        string temp = origin_v[i].first;
        sorted_v.push_back({temp[n], origin_v[i].second});
    }
    
    sort(sorted_v.begin(), sorted_v.end());
    
    for(int i=0; i<sorted_v.size(); i++) answer.push_back(origin_v[sorted_v[i].second].first);
    return answer;
}

int main(){
    vector<string> v;
    v = solution({"sun", "bed", "car"}, 1);
    
    for(auto i : v) cout<< i << " ";
    
    return 0;
}
