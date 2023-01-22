//
//  킹.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/18.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

char field[8][8];

pair<int, int> change_as_int(string inpt){
    char first = inpt[0];
    int second = inpt[1] - '0';
    
    pair<int, int> ret = {8-second, first-'A'};
    
    return ret;
}

string change_as_str(int x, int y){
    string ret;
    
    int temp = 'A'+y;
    ret+=temp;
    ret+=to_string(8-x);
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string king_dir_str, stone_dir_str;
    int n;
    cin>>king_dir_str>>stone_dir_str>>n;
    
    pair<int, int> king_dir = change_as_int(king_dir_str);
    pair<int, int> stone_dir = change_as_int(stone_dir_str);
    field[king_dir.first][king_dir.second] = 'k';
    field[stone_dir.first][stone_dir.second] = 's';
    
    while(n--){
        string cmd;
        
        cin>>cmd;
        
        int nx=0, ny=0;
        
        if(cmd == "R") ny++;
        else if(cmd == "L") ny--;
        else if(cmd == "B") nx++;
        else if(cmd == "T") nx--;
        else if(cmd == "RT"){
            nx--;
            ny++;
        }
        else if(cmd == "LT"){
            nx--;
            ny--;
        }
        else if(cmd == "RB"){
            nx++;
            ny++;
        }
        else if(cmd == "LB"){
            nx++;
            ny--;
        }
        
        int dx = king_dir.first + nx;
        int dy = king_dir.second + ny;
        
        if(dx < 0 || 7<dx || dy<0 || 7<dy) continue;
        if(stone_dir.first == dx && stone_dir.second == dy){
            int stone_dx = stone_dir.first + nx;
            int stone_dy = stone_dir.second + ny;
            if(stone_dx < 0 || 7<stone_dx || stone_dy < 0 || 7<stone_dy) continue;
            
            stone_dir= {stone_dx, stone_dy};
            king_dir = {dx, dy};
        }
        else{
            king_dir = {dx, dy};
        }
    }
    
    cout<<change_as_str(king_dir.first, king_dir.second)<<endl;
    cout<<change_as_str(stone_dir.first, stone_dir.second);

    return 0;
}
