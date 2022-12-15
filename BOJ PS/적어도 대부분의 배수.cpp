//
//  적어도 대부분의 배수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v(5);
    cin>>v[0]>>v[1]>>v[2]>>v[3]>>v[4];
    sort(v.begin(), v.end());
    int i = v[2];
    while(1){
        int found_cnt = 0;
        for(int j=0; j<5; j++){
            if(i % v[j] == 0) found_cnt++;
        }
        if(found_cnt>=3) {
            cout<<i;
            return 0;
        }
        i++;
    }
}
