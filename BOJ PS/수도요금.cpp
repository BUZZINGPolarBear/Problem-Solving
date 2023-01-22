//
//  수도요금.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, d;
    int p;
    
    cin>>a>>b>>c>>d;
    cin>>p;
    
    int x, y;
    
    x = p*a;
    
    if(p<=c) y = b;
    else{
        y = b;
        p -= c;
        int temp = p*d;
        
        y+=temp;
    }
    
    cout<<min(x, y);
    return 0;
}
