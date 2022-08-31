//
//  소수 찾기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/29.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <set>
bool field[10000005];

using namespace std;

int solution(string numbers) {
    int answer = 0;
    set<int> is_dup_set;
    sort(numbers.begin(), numbers.end());
    
    long long n = 10000000;
    for(int i=2; i<sqrt(n); i++){
        if(field[i] == false){
            for(int j=i*i; j<=n; j+=i){
                field[j] = 1;
            }
        }
    }
    
    do{
        for(int i=1; i<=numbers.size(); i++){
            vector<int> temp_v;
            for(int j=0; j<i; j++) temp_v.push_back(1);
            for(int j=0; j<numbers.size()-i; j++) temp_v.push_back(0);
            
            sort(temp_v.begin(), temp_v.end());
            
            
            do{
                string temp_str = "";
                for(int k=0; k<temp_v.size(); k++){
                    if(temp_v[k]==1){
                        temp_str+=numbers[k];
                    }
                }
                
                is_dup_set.insert(stoi(temp_str));
            }while(next_permutation(temp_v.begin(), temp_v.end()));
        }
    }while (next_permutation(numbers.begin(), numbers.end()));
    
    for(auto i : is_dup_set){
        cout<<i<<endl;
        if(i==1 || i==0) continue;
        if(field[i]==0){
            cout<<i<<" 는 "<<field[i]<<" 이고 소수\n";
            answer++;
        }
    }
    
    return answer;
}

int main(){
    cout<<solution("121");
    
    return 0;
}

