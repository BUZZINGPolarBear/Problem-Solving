//
//  같은 숫자는 싫어.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/23.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> st;
    
    for(int i=arr.size()-1; i>=0; i--) st.push(arr[i]);
    
    int temp = st.top();
    st.pop();
    answer.push_back(temp);
    
    while(!st.empty()){
        if(st.top() == temp){
            st.pop();
        }
        else{
            temp = st.top();
            st.pop();
            answer.push_back(temp);
        }
    }
    
    return answer;
}

int main()
{
    solution({1,1,3,3,0,1,1});
}
