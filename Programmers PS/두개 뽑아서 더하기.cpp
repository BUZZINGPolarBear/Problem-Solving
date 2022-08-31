//
//  두개 뽑아서 더하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/31.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> temp_v;
    set<int> set;
    
    sort(numbers.begin(), numbers.end());
    
    for(int i=0; i<numbers.size()-2; i++) temp_v.push_back(0);
    temp_v.push_back(1);
    temp_v.push_back(1);
    
    do{
        int temp = 0;
        for(int i=0; i<temp_v.size(); i++){
            if(temp_v[i] == 1){
                temp += numbers[i];
            }
        }
        set.insert(temp);
    }while(next_permutation(temp_v.begin(), temp_v.end()));
    
    for(auto i : set){
        answer.push_back(i);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> v;
    v = solution({2,1,3,4,1});
    for(auto i : v){
        cout<< i <<" ";
    }
    
    return 0;
}
