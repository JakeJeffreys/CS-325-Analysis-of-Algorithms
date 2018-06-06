//
//  main.cpp
//  group_as3
//
//  Created by Jake on 2/20/16.
//  Copyright © 2016 Jake. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int find_smallest_sum1(int *array , int lower, int upper);
int find_smallest_sum2(int *array , int lower, int upper);

int lower1;
int upper1;
int closestVal1 = 99999999;

int lower2;
int upper2;
int closestVal2 = 99999999;


int main(int argc, const char * argv[]) {
    
    int arraySize = 10;
    int array[10] = {31,-41,59,26,-53,58,-6,97,-93,-23};
    
    int size = (arraySize/2);
    
    int *leftArray = new int[size];
    int *rightArray = new int[size];
    
    int *list1_sum = new int[size];
    int *list2_sum = new int[size];
    
    int *unsorted_array1 = new int[size];
    int *unsorted_array2 = new int[size];
    
    int lsum = 0;
    int rsum = 0;
    
    int lower3;
    int upper3;
    
    
    // SPLIT ARRAY IN HALF --------------------------------
    
    for (int i=0 ; i<(arraySize/2) ; i++){
        leftArray[i] = array[i];
    }
    
    int index = 0;
    for (int i=(arraySize/2) ; i<arraySize ; i++){
        rightArray[index] = array[i];
        index++;
    }
    
    
    // RECURSIVE FUNCTION CALLS --------------------------
    
    find_smallest_sum1(leftArray, 0, size);
    
    
    cout << "Closest Val 1: " << closestVal1 << endl;
    cout << "Lower 1: " << lower1 << endl;
    cout << "Upper 1: " << upper1 << endl;
    cout << endl;
    
    
    find_smallest_sum2(rightArray, 0, size);
    
    lower2 = lower2+size;
    upper2 = upper2+size;
    
    cout << "Closest Val 2: " << closestVal2 << endl;
    cout << "Lower 2: " << lower2 << endl;
    cout << "Upper 2: " << upper2 << endl;
    cout << endl;
    
    
    // MAKE SUM ARRAYS ------------------------------------
    
    for (int i=0 ; i<size ; i++){
        for ( int j=i ; j<size ; j++){
            lsum += leftArray[j];
        }
        list1_sum[i] = lsum;
        lsum=0;
    }
    
    for (int i=0 ; i<size ; i++){
        rsum += rightArray[i];
        list2_sum[i] = rsum;
    }
    
    
    // SORT ARRAYS ---------------------------------------
    
    for (int i=0 ; i<size ; i++){
        unsorted_array1[i] = list1_sum[i];
        unsorted_array2[i] = list2_sum[i];
    }
    
    sort(list1_sum, list1_sum + size);
    sort(list2_sum, list2_sum + size);
    
    
    // COMPARE SUMS IN SORTED ARRAYS --------------------
    
    int buffer_sum;
    int closestVal3=9999999;
    int index1=0, index2=0;
    int uppersum, lowersum;
    
    while (index1 < size){
        buffer_sum = list1_sum[index1]+list2_sum[index2];
        if (abs(buffer_sum) < abs(closestVal3) && index2<size){
            closestVal3 = buffer_sum;
            lowersum = list1_sum[index1];
            uppersum = list2_sum[index2];
            index2++;
        } else {
            index1++;
            index2=0;
        }
    }

    
    cout << "Closest Val 3: " << closestVal3 << endl;
    
    for (int i=0 ; i<size ; i++){
        if (lowersum == unsorted_array1[i]){
            lower3 = i;
        }
        if (uppersum == unsorted_array2[i]){
            upper3 = i;
        }
    }
    
    upper3 = upper3+size;
    
    cout << "Lower 3 : " << lower3 << endl;
    cout << "Upper 3 : " << upper3 << endl;
    cout << endl;
    
    
    // COMPARE CLOSEST VALUES --------------------------
    
    cout << "FINAL RESULT ------------------- " << endl;
    
    closestVal1 = abs(closestVal1);
    closestVal2 = abs(closestVal2);
    closestVal3 = abs(closestVal3);
    
    if (closestVal1<closestVal2 && closestVal1<closestVal3){
        cout << "Closest Val 1: " << closestVal1 << endl;
        cout << "Lower 1: " << lower1 << endl;
        cout << "Upper 1: " << upper1 << endl;
    }
    
    if (closestVal2<closestVal1 && closestVal2<closestVal3){
        cout << "Closest Val 2: " << closestVal2 << endl;
        cout << "Lower 2: " << lower2 << endl;
        cout << "Upper 2: " << upper2 << endl;
    }
    
    if (closestVal3<closestVal2 && closestVal3<closestVal1){
        cout << "Closest Val 3: " << closestVal3 << endl;
        cout << "Lower 3 : " << lower3 << endl;
        cout << "Upper 3 : " << upper3 << endl;
    }
    
    cout << endl;
    
}





int find_smallest_sum1(int *array1 , int lower, int upper){
    
    if ( lower == upper )
        return 0;
    
    int sum=0;
    for (int i=lower ; i<upper ; i++){
        sum+=array1[i];
        if (abs(sum)<abs(closestVal1)){
            closestVal1 = sum;
            lower1 = lower;
            upper1 = i;
        }
    }
    
    return find_smallest_sum1(array1, lower+1, upper);
    
}


int find_smallest_sum2(int *array2 , int lower, int upper){
    
    if ( lower == upper )
        return 0;
    
    int sum=0;
    for (int i=lower ; i<upper ; i++){
        sum+=array2[i];
        if (abs(sum)<abs(closestVal2)){
            closestVal2 = sum;
            lower2 = lower;
            upper2 = i;
        }
    }
    
    return find_smallest_sum2(array2, lower+1, upper);
    
}
