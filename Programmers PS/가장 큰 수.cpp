//
//  가장 큰 수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/06.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end());
    string old_temp = "", temp ="";
    for(int i=0; i<numbers.size(); i++) old_temp += "0";
    
    do{
        temp = "";
        for(auto i:numbers) temp += to_string(i);
        
        for(int i=0; i<temp.size();i++){
            if(temp[i] > old_temp[i]){
                old_temp = temp;
                break;
            }
            else if(temp[i] < old_temp[i]) break;
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    for(int i=0; i<temp.size();i++){
        if(temp[i] > old_temp[i]){
            old_temp = temp;
            break;
        }
        else if(temp[i] < old_temp[i]) break;
    }
    
    return old_temp;
}

int main(){
    string temp = solution({6, 10, 2});
    
    cout<< temp;
    
    return 0;
}
