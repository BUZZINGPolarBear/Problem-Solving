//
//  내려가기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/09.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> max_field(3);
vector<long long> old_max;
vector<long long> min_field(3);
vector<long long> old_min;

int main(){
    using namespace std; cin.tie(0); cout.tie(0);
    
    int n;
    int row = 1;
    cin>>n;
    
    long long temp;
    cin>>temp;
    max_field[0] = temp;
    min_field[0] = temp;
    
    cin>>temp;
    max_field[1] = temp;
    min_field[1] = temp;
    
    cin>>temp;
    max_field[2] = temp;
    min_field[2] = temp;
    
    old_max = max_field;
    old_min = min_field;
    
    for(int i=3; i<n*3; i++){
        long long inpt;
        cin>>inpt;
        
        if(i%3 == 0) {
            max_field[0] = max(inpt+old_max[0], inpt+old_max[1]);
            min_field[0] = min(inpt+old_min[0], inpt+old_min[1]);
//            cout<<field[row][0]<<" ";
        }
        else if(i%3 == 1) {
            max_field[1] = max(inpt+old_max[0], max(inpt+old_max[1], inpt+old_max[2]));
            min_field[1] = min(inpt+old_min[0], min(inpt+old_min[1], inpt+old_min[2]));
//            cout<<field[row][1]<<" ";
        }
        else if(i%3 == 2){
            max_field[2] = max(inpt+old_max[1], inpt+old_max[2]);
            min_field[2] = min(inpt+old_min[1], inpt+old_min[2]);
            
            old_max = max_field;
            old_min = min_field;
//            cout<<field[row][2]<<" ";
//            cout<<"\n";
        }
        
        
    }
    
    cout<<max(max_field[0], max(max_field[1], max_field[2]))<<' '<<min(min_field[0], min(min_field[1], min_field[2]));
    return 0;
}
