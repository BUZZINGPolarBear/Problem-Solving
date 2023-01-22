//
//  마법사 상어와 비바라기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int field[55][55];
bool current_cloud[55][55];
vector<pair<int, int> > cloud_v;
vector<pair<int, int> > cmd;
int n, m;
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void print_field(int i){
    cout<<"\n FIELD 상태: "<<i<<"번 이동 후 \n";
    for(int i=1;i<=n; i++){
        for(int j=1;j<=n; j++){
            cout<<field[i][j]<<" ";
        }
        cout<<endl;
    }
}
void clear_cloud(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            current_cloud[i][j] = false;
        }
    }
}
void input(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>field[i][j];
        }
    }
    
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        
        cmd.push_back({a, b});
    }
    
    cloud_v.push_back({n, 1});
    cloud_v.push_back({n, 2});
    cloud_v.push_back({n-1, 1});
    cloud_v.push_back({n-1, 2});
    current_cloud[n][1] = 1;
    current_cloud[n][2] = 1;
    current_cloud[n-1][1] = 1;
    current_cloud[n-1][2] = 1;
}

int Make_Range(int x)
{
    if (x < 1) return n;
    if (x >= n+1) return 1;
    return x;
}

void move_clouds(int stage){
    int dir = cmd[stage].first;
    int distance = cmd[stage].second;
    clear_cloud();
    
    for(int i=0; i<cloud_v.size(); i++){
        int x = cloud_v[i].first;
        int y = cloud_v[i].second;
        int nx = x;
        int ny = y;
        for(int j=0; j<distance; j++){
            nx += dx[dir];
            ny += dy[dir];
            nx = Make_Range(nx);
            ny = Make_Range(ny);
        }
        cloud_v[i].first = nx;
        cloud_v[i].second = ny;
    }
    
    for(int i=0; i<cloud_v.size(); i++){
        current_cloud[cloud_v[i].first][cloud_v[i].second] = true;
    }
}

void make_rain(){
    for(int i=0; i<cloud_v.size(); i++){
        field[cloud_v[i].first][cloud_v[i].second]++;
    }
}

void water_bug(){
    int temp_dx[4] = {-1, 1, 1, -1};
    int temp_dy[4] = {-1, -1, 1, 1};
    
    for(int i=0; i<cloud_v.size(); i++){
        int now_x = cloud_v[i].first;
        int now_y = cloud_v[i].second;
        
        int temp = 0;
        for(int j=0; j<4; j++){
            int dx = now_x + temp_dx[j];
            int dy = now_y + temp_dy[j];
            
            if(1<=dx && dx<=n && 1<=dy && dy<=n){
                if(field[dx][dy] >0) temp++;
            }
        }
        
        field[now_x][now_y] += temp;
    }
}

void delete_cloud(){
    cloud_v.clear();
}

void make_cloud(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(field[i][j] >= 2 && current_cloud[i][j] == false){
                field[i][j] -= 2;
                cloud_v.push_back({i, j});
            }
        }
    }
}

long long find_ans(){
    long long ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans += field[i][j];
        }
    }
    
    return ans;
}
void solve(){
    input();
    for(int i=0; i<m; i++){
        move_clouds(i);
        make_rain();
        
        water_bug();
//        print_field(i);
        delete_cloud();
        make_cloud();
        
    }
    
    cout<<find_ans();
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    
    return 0;
}
