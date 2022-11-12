//
//  연속 부분 수열 합의 개수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/06.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    set<int> ans_set;
    queue<int> q;
    
    for(auto i:elements) q.push(i);
    
    for(int i=1; i<=size; i++){
        for(int k=0; k<size; k++){
            long long sum = 0;
            queue<int> temp;
            temp = q;
            for(int j=0; j<i; j++){
                sum += temp.front();
                temp.push(temp.front());
                temp.pop();
            }
            
            ans_set.insert(sum);
            q.push(q.front());
            q.pop();
        }
        
        
        q.push(q.front());
        q.pop();
    }
    
    return ans_set.size();
}

int main()
{
    cout<<solution({7,9,1,1,4});
    return 0;
}
