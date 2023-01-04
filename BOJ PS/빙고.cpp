//
//  빙고.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/03.
//

#include <iostream>
#include <map>
using namespace std;

bool visited[10][10] = {0, };
int field[10][10] = {0, };

void visited_print(int i){
    cout<<"\n===============\n";
    cout<<i<<"th result\n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}
int bingo_cnt(){
    int ans=0;
    //가로, 세로줄 검사
    for(int i=0; i<5; i++){
        int result_r = 0;
        int result_c = 0;
        
        for(int j=0; j<5; j++){
            if(visited[i][j] == 1) result_r++;
            if(visited[j][i] == 1) result_c++;
        }
        if(result_r == 5) ans++;
        if(result_c == 5) ans++;
    }
    
    //대각 검사
    int right=0;
    for(int i=0; i<5; i++){
        if(visited[i][i] == 1) right++;
    }
    if(right==5) ans++;
    
    int left=0;
    for(int i=4; i>=0; i--){
        if(visited[4-i][i] == 1) left++;
    }
    if(left==5) ans++;
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    map<int, int> map;
    
    for(int i=0; i<25; i++){
        int temp;
        cin>>temp;
        
        field[i/5][i  - ((i/5)*5)] = temp;
        map.insert({temp, i});
    }
    
    for(int i=1; i<=25; i++){
        int temp;
        cin>>temp;
        
        int num = map[temp];
//        cout<<"\n"<<num/5<<", "<<num - ((num/5)*5)<<"\n";
        visited[num/5][num - ((num/5)*5)] = 1;
        
        if(i>=12){
//            visited_print(i);
            if(bingo_cnt() >= 3){
                cout<<i;
                return 0;
            }
        }
    }
}
