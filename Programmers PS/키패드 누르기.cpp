//
//  키패드 누르기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/10.
//

const int dx[4]={-1, 1, 0, 0};
const int dy[4]={0, 0, -1, 1};

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int moveCnt(int current_hand, int goal_num){
    pair<int, int> current_coordinate, goal_coordinate;
    int total_move = 0;
    if(goal_num==0) goal_num=11;
    
    current_coordinate = {(current_hand-1)/3, (current_hand-1)%3};
    goal_coordinate = {(goal_num-1)/3, (goal_num-1)%3};
    
    current_coordinate.first > goal_coordinate.first ? total_move += current_coordinate.first - goal_coordinate.first : total_move += goal_coordinate.first - current_coordinate.first;
    current_coordinate.second > goal_coordinate.second ? total_move += current_coordinate.second - goal_coordinate.second : total_move += goal_coordinate.second - current_coordinate.second;
    
    return total_move;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int current_left=10, current_right=12;
    for(auto i:numbers){
        if(i==0) i = 11;
        if(i==1 || i==4 || i ==7){
            current_left = i;
            answer+="L";
        }
        else if(i==3 || i==6 || i==9){
            current_right = i;
            answer+="R";
        }
        else{
            int left_move = moveCnt(current_left, i);
            int right_move = moveCnt(current_right, i);
            if(left_move == right_move){
                if(hand == "left"){
                    answer += "L";
                    current_left = i;
                }
                else if (hand=="right"){
                    answer += "R";
                    current_right = i;
                }
            }
            else if(left_move < right_move){
                answer += "L";
                current_left = i;
            }
            else if(right_move < left_move){
                answer += "R";
                current_right = i;
            }
        }
    }
    
    return answer;
}



int main()
{
    vector<int> testV = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string testS = "right";
    
    cout<<solution(testV, testS);
    return 0;
}
