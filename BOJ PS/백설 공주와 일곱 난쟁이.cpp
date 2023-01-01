//
//  백설 공주와 일곱 난쟁이.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v(9);
    vector<int>::iterator iter = v.begin();
    int sum = 0;
    
    for(int i=0; i<9; i++){
        cin>>v[i];
        sum += v[i];
    }
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(v[i] + v[j] == sum - 100){
                v.erase(iter + i);
                v.erase(iter + j-1);
                for(auto i:v) cout<<i<<"\n";
                return 0;
            }
        }
    }
    
    
}
