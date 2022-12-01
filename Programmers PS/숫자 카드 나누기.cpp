//
//  숫자 카드 나누기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/23.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define max 100000005
using namespace std;

vector<int> candidates(vector<int> vA){
    int startA = vA[0];
    int size = vA.size();
    vector<int> candidates;
    bool check = 1;
    
      for(int i=0; i<size; i++){
        if(vA[i]%startA != 0) {
            check = 0;
            break;
        }
    }
    if(check){
        for(int i=0; i<size; i++){
            if(vA[i]%startA != 0){
                check = 0;
                break;
            }
        }
    }
    if(check) candidates.push_back(startA);
    startA /= 2;
    
    while(startA >=2){
        bool localCheck = 1;
        
        for(int i=0; i<size; i++){
            if(vA[i]%startA != 0) {
                localCheck = 0;
                break;
            }
        }
        if(check){
            for(int i=0; i<size; i++){
                if(vA[i]%startA != 0){
                    localCheck = 0;
                    break;
                }
            }
        }
        if(localCheck) candidates.push_back(startA);
        startA--;
    }
    
    return candidates;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int size = arrayA.size();
    int aMax = -10, bMax=-10;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    vector<int> Acandidates = candidates(arrayA),
                Bcandidates = candidates(arrayB);
    
    if(Acandidates.size() > 0){
        bool check = 1;
        for(int i=0; i<Acandidates.size(); i++){
            for(int j=0; j<size; j++){
                if(arrayB[j] % Acandidates[i] ==0) check = 0;
            }
            
            if(check) aMax < Acandidates[i] ? aMax = Acandidates[i] : aMax;
        }
    }
    
    if(Bcandidates.size() > 0){
        bool check = 1;
        for(int i=0; i<Bcandidates.size(); i++){
            for(int j=0; j<size; j++){
                if(arrayA[j] % Bcandidates[i] ==0) check = 0;
            }
            
            if(check) bMax < Bcandidates[i] ? bMax = Bcandidates[i] : bMax;
        }
    }
    
    aMax <= bMax ? answer = bMax : answer = aMax;
    
    if(answer == -10) return 0;
    return answer;
}

int main(){
    cout<<solution({14, 35, 119}, {18, 30, 102});
    return 0;
}
