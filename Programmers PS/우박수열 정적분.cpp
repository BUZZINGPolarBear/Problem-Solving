//
//  우박수열 정적분.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/06.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> up_down_v, acc_sum_v;
    
    up_down_v.push_back(k);
    while(1){
        if(k == 1) break;
        else{
            if(k%2 == 0) k /=2;
            else if(k%2 == 1){
                k *= 3;
                k++;
            }
            up_down_v.push_back(k);
        }
    }
    
    for(int i=1; i<=up_down_v.size(); i++){
        acc_sum_v.push_back((up_down_v[i-1] + up_down_v[i])/2);
    }
    
    for(int i=0; i<ranges.size(); i++){
        int left = ranges[i][0];
        int right = acc_sum_v.size()+ranges[i][1];
        
        if(right-1<left) {
            answer.push_back(-1);
        }
        else if(right==left){
            answer.push_back(0.0);
        }
        else{
            double temp = 0;
            for(int j=left; j<right-1; j++){
                temp += acc_sum_v[j];
            }
            answer.push_back(temp);
        }
    }
    
    return answer;
}

int main(){
    vector<double> temp = solution(5, {{0,0},{0,-1},{2,-3},{3,-3}});
    for(auto i:temp){
        cout<<i<<" ";
    }
}
