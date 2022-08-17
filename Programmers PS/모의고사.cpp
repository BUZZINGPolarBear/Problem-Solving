//
//  모의고사.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/13.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int max_ans=-100;
    int a_ans=0, b_ans=0, c_ans=0;
    vector<int> answer;
    vector<int> a = {1, 2, 3, 4, 5}, b={2, 1, 2, 3, 2, 4, 2, 5}, c={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    if(answers[0]==a[0]) a_ans++;
    if(answers[0]==b[0]) b_ans++;
    if(answers[0]==c[0]) c_ans++;
    
    for(int i=1; i<answers.size(); i++){
        if(answers[i]==a[i%5]) {
            a_ans++;
            if(a_ans > max_ans) max_ans = a_ans;
        }
        if(answers[i]==b[i%8]){
            b_ans++;
            if(b_ans > max_ans) max_ans = b_ans;
        }
        if(answers[i]==c[i%10]) {
            c_ans++;
            if(c_ans > max_ans) max_ans = c_ans;
        }
    }
    
    if(a_ans==max_ans) answer.push_back(1);
    if(b_ans==max_ans) answer.push_back(2);
    if(c_ans==max_ans) answer.push_back(3);
    
    
    return answer;
}

int main(){
    vector<int> ans = solution(vector<int> {1,2,3,4,5});
    
    for(auto i : ans){
        cout<< i <<" ";
    }
    return 0;
}
