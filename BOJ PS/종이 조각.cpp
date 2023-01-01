//
//  종이 조각.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char field[5][5];
int n, m;
int local_result(int mask[5][5]){
    bool visited[5][5] = {0, };
    vector<int> v;
    int sum=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            string temp;
            if(mask[i][j] == 0){
                //가로 탐색
                for(int k=j; k<m; k++){
                    if(mask[i][k] == 0 && visited[i][k] == 0){
                        temp += field[i][k];
                        visited[i][k] = 1;
                    }
                    else break;
                }
            }
            if(mask[i][j] == 1){
                //세로로 연결
                for(int k=i; k<n; k++){
                    if(mask[k][j] == 1 && visited[k][j] == 0){
                        temp += field[k][j];
                        visited[k][j] = 1;
                    }
                    else break;
                }
                
            }
            if(temp.size()) sum += stoi(temp);
        }
    }
    
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    int ans=-987654321;
    int cnt = 0;
    vector<string> inptString(n);
    for(int i=0; i<n; i++){
        cin>>inptString[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            field[i][j] = inptString[i][j];
        }
    }
    
    for(int i=0; i < (1<<(n*m)); i++){
        int mask[5][5]={0, };
        for(int j=0; j<(n*m); j++){
            if(i&(1<<j)){
//                cout<<"found: "<<j<<endl;
                int row = j/m;
                int col = j - (row*m);
//                cout<<j<<" is AT {"<<row<<", "<<col<<")"<<endl;
                mask[row][col] = 1;
            }
            cnt++;
        }
        
//        for(int i=0; i<n; i++){
//            for(int j=0; j<m; j++) cout<<mask[i][j]<<" ";
//            cout<<endl;
//        }
        
        int temp = local_result(mask);
//        cout<<"Local Ans : "<<temp<<"\n==============\n";
        ans = max(ans, temp);
    }
//    cout<<cnt<<'\n';
    cout<<ans;
    return 0;
}
