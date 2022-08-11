//
//  크레인 인형뽑기 게임.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/11.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> ans_st;
    int size = board[0].size();
    
    for(auto i : moves){
        for(int j=0; j<size; j++){
            if(board[j][i-1]!=0){
                const int pop_top = board[j][i-1];
                board[j][i-1] = 0;
                
                if(!ans_st.empty() && ans_st.top()==pop_top ){
                        ans_st.pop();
                        answer++;
                }
                else{
                    ans_st.push(pop_top);
                }
                break;
            }
        }
    }
    return answer*2;
}

int main()
{
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    
    cout<<solution(board, moves);
    
    return 0;
}
