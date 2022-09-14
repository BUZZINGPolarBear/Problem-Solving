//
//  프린터.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int> > v;
    
    for(int i=0; i<priorities.size(); i++){
        if(i == location) v.push_back({priorities[i], 1});
        else v.push_back({priorities[i], 0});
    }
    
    while(v.size() > 0){
        bool is_found = false;
        int first = v[0].first;
        
        for(int i=1; i<v.size(); i++){
            if(v[i].first > first){
                is_found = true;
                break;
            }
        }
        
        if(is_found){
            v.push_back({v[0].first, v[0].second});
            v.erase(v.begin());
        }
        else{
            answer++;
            
            if(v[0].second == 1) return answer;
            v.erase(v.begin());
        }
    }
    return answer;
}

int main(){
    cout<<solution({1}, 0);
    
    return 0;
}
