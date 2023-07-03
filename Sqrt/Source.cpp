#include<iostream>
#include<algorithm>
#include <cassert> 

using namespace std;

int mySqrt(int x){

    int start = 0, middle, sqrt;
    unsigned int end = x + 1;

    while (end - start > 1) {

        middle = (start + end) / 2;
        sqrt = x / middle;

        if (sqrt == middle && x % middle == 0) {
            return middle;
        }

        if (middle > sqrt) {
            end = middle;
        }
        else {
            start = middle ;
        }
        
    }

    return start;
}


int main() {
    cout << mySqrt(2147483647);
    
}