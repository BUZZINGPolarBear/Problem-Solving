//
//  보물지도.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/02.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        string arr1_str ="", arr2_str = "";
        while(arr1[i]){
            if(arr1[i]%2 == 1){
                arr1_str = '1'+arr1_str;
            }
            else if(arr1[i]%2 == 0){
                arr1_str = '0' + arr1_str;
            }
            arr1[i] /= 2;
        }
        
        while(arr2[i]){
            if(arr2[i]%2 == 1){
                arr2_str = '1' + arr2_str;
            }
            else if(arr2[i]%2 == 0){
                arr2_str = '0' + arr2_str;
            }
            arr2[i] /= 2;
        }
        string temp_str = "";
        
        if(arr1_str.size() < arr2_str.size()){
            string temp_change_arr;
            
            temp_change_arr = arr1_str;
            arr1_str = arr2_str;
            arr2_str = temp_change_arr;
        }
        
        while(arr1_str.size() < n){
            arr1_str = '0' + arr1_str;
        }
        while(arr2_str.size() < n){
            arr2_str = '0' + arr2_str;
        }
        
        for(int j=0; j<arr1.size(); j++){
            if(arr1_str[j] == '1' || arr2_str[j] == '1') temp_str += '#';
            else temp_str += ' ';
        }
        answer.push_back(temp_str);
    }
    return answer;
}

int main(){
    vector<string> ans = solution(6, {31, 22, 46, 33, 33, 50}, {14, 14, 27 ,56, 19, 10});
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}
