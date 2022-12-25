//
//  마방진.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/25.
//

#include <iostream>
using namespace std;

int original[3][3];
int ans[3][3];

int find_sum(){
    for (int i = 0; i< 3; i++){
        if (original[i][0] && original[i][1] && original[i][2]) return original[i][0]+original[i][1]+original[i][2];
        if (original[0][i] && original[1][i] && original[2][i]) return original[0][i] + original[1][i] + original[2][i];
    }
    if (original[0][0] && original[1][1] && original[2][2]) return original[0][0]+ original[1][1] + original[2][2];
    if (original[0][2] && original[1][1] && original[2][0]) return original[0][2] + original[1][1] + original[2][0];
    int max_sum = 0;
    for (int i = 0 ; i < 3; i++){
        for (int j= 0;j<3;j++){
            max_sum += original[i][j];
        }
    }
    return max_sum/2;
}

int main(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int temp;
            cin>>temp;
            original[i][j] = temp;
            ans[i][j] = temp;
        }
    }
    
    int objective= find_sum();
    
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(ans[i][j] == 0){
                int rtemp =0, r_zero_cnt=0;
                for(int r=0; r<3; r++){
                    if(original[r][j]==0) r_zero_cnt++;
                    rtemp += original[r][j];
                }
                if(r_zero_cnt == 1) {
                    ans[i][j] = objective - rtemp;
                    original[i][j] = objective - rtemp;
                }
                
                if(r_zero_cnt >= 2){
                    int ctemp =0, c_zero_cnt=0;
                    for(int c=0; c<3; c++){
                        if(original[i][c]==0) c_zero_cnt++;
                        ctemp += original[i][c];
                    }
                    if(c_zero_cnt==1) {
                        ans[i][j] = objective - ctemp;
                        original[i][j] = objective - ctemp;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(ans[i][j] == 0){
                int rtemp =0, r_zero_cnt=0;
                for(int r=0; r<3; r++){
                    if(original[r][j]==0) r_zero_cnt++;
                    rtemp += original[r][j];
                }
                if(r_zero_cnt == 1) ans[i][j] = objective - rtemp;
                
                if(r_zero_cnt >= 2){
                    int ctemp =0, c_zero_cnt=0;
                    for(int c=0; c<3; c++){
                        if(original[i][c]==0) c_zero_cnt++;
                        ctemp += original[i][c];
                    }
                    ans[i][j] = objective - ctemp;
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
