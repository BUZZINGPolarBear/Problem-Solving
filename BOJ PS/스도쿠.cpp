#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
int zero_cnt = 0;
int field[9][9] = {0, };
int copy_field[9][9] = {0, };
vector<pair<int, int> > zero_v;
bool end_flag = 0;

void input(){
    int temp;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>temp;
            
            if(temp == 0){
                zero_cnt++;
                zero_v.push_back({i, j});
                field[i][j] = 0;
            }
            else field[i][j] = temp;
        }
    }
}

bool check(pair<int, int> point){
    int x_coor = point.first;
    int y_coor = point.second;

    for(int i=0; i<9; i++){
        if(field[x_coor][i] == field[x_coor][y_coor] && i != y_coor) return 0;
        if(field[i][y_coor] == field[x_coor][y_coor] && i != x_coor) return 0;
    }


    int rect_x = x_coor / 3;
    int rect_y = y_coor / 3;

    for(int i=3*rect_x; i < 3*rect_x + 3; i++){
        for(int j=3*rect_y; j < 3*rect_y + 3; j++){
            if(field[i][j] == field[x_coor][y_coor]){
                if(i != x_coor && j != y_coor) return 0;
            }
        }
    }

    return 1;
}

void back_tracking(int n){
    if(n == zero_cnt){
        end_flag = true;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<field[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        return;
    }
    
    for(int i=1; i<=9; i++){
        
        field[zero_v[n].first][zero_v[n].second] = i;
        
        if(check(zero_v[n]) == 1){
            back_tracking(n+1);
        }
        if(end_flag == 1) return;
    }
    
    field[zero_v[n].first][zero_v[n].second] = 0;
    return;
}

void solve(){
    input();
    
    back_tracking(0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
