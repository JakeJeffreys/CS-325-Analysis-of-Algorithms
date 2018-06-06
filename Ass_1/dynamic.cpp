#include <iostream>

using namespace std;

int main() {
    
    int biggest = 0;
    int sum = 0;
    
    int array_size = 100;
    
    int array[100] = {-18, -47, -40, -43, -2, 48, 31, -24, 36, -49, 4, -29, -4, -39, 12, 24, 8, 40, 45, -17, 6, -11, -5, -30, -8, 25, -44, -9, -20, -50, -12, -32, 41, 10, -42, -15, 11, -38, 37, 21, 33, -22, 16, -41, -46, -33, -26, 7, -3, -28, 29, 20, 27, 3, 15, 49, 23, -1, 14, 32, -31, -13, -48, -14, 13, 39, 46, -35, -36, 0, 17, -27, -21, 28, -7, 44, -10, 34, -19, 47, 42, -34, 5, 26, -45, 35, 9, -25, 38, -37, -23, 22, -6, -16, 18, 43, 30, 2, 19, 1};
    
    //int size = array.size();
    
    for (int i = 0; i < array_size; i++) {
        
        if (array[i] < 0)
            sum = max(0, sum + array[i]);
        
        else
            sum = max(array[i], sum + array[i]);
        
        biggest = max(biggest, sum);
        
    }
    
    cout << "max sum is: " << biggest << endl;
    
    return 0;
    
}


