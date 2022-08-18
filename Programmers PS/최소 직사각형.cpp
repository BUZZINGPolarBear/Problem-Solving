//
//  최소 직사각형.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/18.
//

#include <iostream>
#include <algorithm>

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int >> sizes) {
    int answer = 0;
    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++){
        int max_val = max(sizes[i][0], sizes[i][1]);
        int min_val = min(sizes[i][0], sizes[i][1]);
        w = max(w, max_val);
        h = max(h, min_val);
    }
    
    return w*h;
}

int main(){
    cout<<solution({{60, 50}, {30, 70}, {60, 30}, {80, 40}});
    
    return 0;
}
