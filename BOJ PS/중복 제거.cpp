//
//  중복 제거.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/01.
//

#include <stdio.h>
using namespace std;

int field[(1<<20) + 2];
int n, idx, shift;

int main(){
    
    while(scanf("%d", &n) != -1){
        idx = n/32;
        shift = n%32;
        
        if(field[idx] & (1<<shift)) continue;
        
        printf("%d ", n);
        field[idx] += (1<<shift);
    }
}
