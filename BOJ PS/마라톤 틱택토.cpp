//
//  마라톤 틱택토.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/19.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    char field[35][35] = {0, };
    int n;
    vector<string> v;
    cin>>n;
    
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            field[i][j] = v[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-2; j++){
            if(field[i][j] == '.' || field[i][j+1] == '.' || field[i][j+2] == '.') continue;
//            cout<<field[i][j]<<" "<<field[i][j+1]<<" "<<field[i][j+2]<<"\n";
            if(field[i][j] == field[i][j+1] && field[i][j] == field[i][j+2]){
                cout<<field[i][j];
                return 0;
            }
        }
    }
    

    for(int i=0; i<n-2; i++){
        for(int j=0; j<n; j++){
            if(field[i][j] == '.' || field[i+1][j] == '.' || field[i+2][j] =='.') continue;
//            cout<<field[i][j]<<" "<<field[i+1][j]<<" "<<field[i+2][j]<<"\n";
            if(field[i][j] == field[i+1][j] && field[i][j] == field[i+2][j]){
                cout<<field[i][j];
                return 0;
            }
        }
    }
    
//    cout<<"=======================\n";
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=n-1; j++){
            if(field[i-1][j-1] == '.' || field[i][j] == '.' || field[i+1][j+1] == '.' ) continue;
//            cout<<"i: "<<i<<" j: "<<j<<" :::";
//            cout<<field[i-1][j-1] <<" " << field[i][j]<<" "<<field[i+1][j+1]<<endl;
            if(field[i][j] == field[i-1][j-1] && field[i][j] == field[i+1][j+1]){
                cout<<field[i][j];
                return 0;
            }
        }
    }
    
//    cout<<"=======================\n";
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=n-1; j++){
            if(field[i][j] == '.' || field[i-1][j+1] == '.' || field[i+1][j-1] == '.') continue;
//            cout<<field[i][j] <<" " <<field[i-1][j+1]<<" "<<field[i+1][j-1]<<endl;
            if(field[i][j] == field[i-1][j+1] && field[i][j] == field[i+1][j-1]){
                cout<<field[i][j];
                return 0;
            }
        }
    }
    
    cout<<"ongoing";
    return 0;
}

