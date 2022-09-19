//
//  스텔라(STELLA)가 치킨을 선물했어요.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> first, pair<int, int> next){
    int first_first = first.first;
    int first_second = first.second;
    
    int next_first = next.first;
    int next_second = next.second;
    
    if(first_first > next_first) return 1;
    else if(first_first == next_first) return first_second < next_second;
    else return 0;
}

int main(){
    int n;
    int answer = 0;
    vector<pair<int, int> > v;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int temp_a, temp_b;
        cin>>temp_a>>temp_b;
        
        v.push_back({temp_a, temp_b});
    }
    
    sort(v.begin(), v.end(), compare);
    
    int temp = v[4].first;
    for(int i=5; i<v.size(); i++){
        if(v[i].first == temp) answer ++;
        else break;
    }
    cout<<answer;
    return 0;
}
