//
//  택배상자.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/07.
//

#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> q;
    stack<int> st;
    
    for(int i=1; i<=order.size(); i++){
        q.push(i);
    }
    
    for(int i=0; i<order.size(); i++){
        if(q.front() == order[i]){
            q.pop();
            answer++;
        }
        else if(q.front() < order[i]){
            if(st.empty()==0 && st.top() == order[i]){
                st.pop();
                answer++;
                continue;
            }
            while(q.front() != order[i]){
                st.push(q.front());
                q.pop();
            }
            q.pop();
            answer++;
        }
        else if(q.front() > order[i]){
            if(st.empty()==0 && st.top() == order[i]){
                st.pop();
                answer++;
            }
            else{
                break;
            }
        }
    }
    return answer;
}

int main(){
    cout<<solution({5, 4, 3, 2, 1});
    return 0;
}
