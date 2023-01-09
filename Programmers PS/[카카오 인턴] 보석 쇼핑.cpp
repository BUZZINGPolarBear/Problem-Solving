//
//  [카카오 인턴] 보석 쇼핑.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/09.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> origin_set, temp_set;
    map<string, int> gem_map;
    
    for(auto i:gems) {
        origin_set.insert(i);
    }
    
    int left=0;
    int right=0;
    int min_size=987654321;
    while(left<=right && right<gems.size()){
        gem_map[gems[right]] += 1;
        if(gem_map.size() == origin_set.size()){
            for(left; left<right; left++){
                if(gem_map[gems[left]] - 1 >= 1){
                    gem_map[gems[left]] -= 1;
                }
                else {
                    break;
                }
            }
                
            if(right - left < min_size ){
                min_size = right - left;
                answer[0] = left+1;
                answer[1] = right+1;
                gem_map.erase(gems[left]);
                left += 1;
            }
        }
        right++;
    }
    
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    vector<int> ans(2);
    ans = solution({"A", "B", "B", "C", "A"});
    
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
