#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>


using namespace std;


int main(){

    
    
    long int quotient;
    
    // Values to change
    int arraySize = 14;
    int numberOfKeys = 12;
    int numberOfBalls = 8;
    
    int keyArray[numberOfKeys];
    int ballArray[numberOfBalls];
    
    
    // Read key input from file
    ifstream file1("input1.txt");
    if(file1.is_open()){
        
        for(int i = 0; i < numberOfKeys; ++i){
            file1 >> keyArray[i];
        }
        
    } else {
        cout << "Unable to open file";
    }
    file1.close();
    cout << endl;
    
    
    
    // Read ball input from file
    ifstream file2("input2.txt");
    if(file2.is_open()){
        
        for(int i = 0; i < numberOfBalls; ++i){
            file2 >> ballArray[i];
        }
        
    } else {
        cout << "Unable to open file";
    }
    file2.close();
    cout << endl;
    
    
    // Sort Key Array
    cout <<  "Sorted Key Array: ";
    sort(keyArray, keyArray + numberOfKeys);
    for ( int i=0 ; i<numberOfKeys ; i++){
        cout << keyArray[i] << " ";
    }
    cout << endl;
    
    
    // Sort Ball Array
    cout <<  "Sorted Ball Array: ";
    sort(ballArray, ballArray + numberOfBalls);
    for ( int i=0 ; i<numberOfBalls ; i++){
        cout << ballArray[i] << " ";
    }
    cout << endl;
    
    
    
    int binaryArray[numberOfKeys];
    int long numCombinations = pow(2,numberOfKeys);
    
    int index=0;
    int keysUsed;
    
    int finalSteps=1000;
    
    
    cout << "\n-------------------------------------------\n" << endl;
    
    
    // Create Binary Array
    for (int count=0 ; count<numCombinations ; count++){
        
        keysUsed=0;
        
        // Initialize array
        for(int a=0 ; a<numberOfKeys ; a++){
            binaryArray[a]=0;
        }
        
        // Store Binary value
        int store = numberOfKeys-1;
        quotient = count;
        while(quotient!=0){
            binaryArray[store--]= quotient % 2;
            quotient = quotient / 2;
        }
        
        // How many keys used
        for(int j=0 ; j<numberOfKeys ; j++ ){
            if(binaryArray[j] == 1){
                keysUsed++;
            }
        }
        
        // Create array of used key indexes
        int usedKeys[keysUsed];
        index=0;
        for( int a=0 ; a<numberOfKeys ; a++){
            if ( binaryArray[a] == 1){
                usedKeys[index++] = keyArray[a];
            }
        }
        
        // Initialize variables
        int lKey,lBall;
        int steps=0;
        int nextKey;
        int rightMostBall;
        int addedSteps=0;
        
        lKey = usedKeys[0];
        lBall = ballArray[0];
        index=0;
        
        int difference;
        int usedFirstStatus=0;
        
        // Test balls on left of first key
        if ( lKey > lBall){
            difference = lKey-lBall;
            steps=difference+1;
            usedFirstStatus=1;
        }
        
        // Rotate through keys
        while (index < keysUsed){
            
            lKey = usedKeys[index];
            
            // Test if there is a key to the right of current key
            if ( index == keysUsed-1){
                nextKey = arraySize+1;
            } else {
                nextKey = usedKeys[index+1];
            }
            
            // Create Range and store right most ball location (if it exists)
            rightMostBall = lKey-1; // Initializes right most ball location
            for (int a=0 ; a<numberOfBalls ; a++){
                if ( ballArray[a] >= lKey && ballArray[a] < nextKey){
                    rightMostBall = ballArray[a];
                }
            }
            
            // Test if ball was detected in range
            if ( (rightMostBall-lKey) != -1 ) {
                addedSteps = (rightMostBall - lKey)+1; // Plus one to include locker
                
                // Test so we dont count first locker twice
                if (index==0 && usedFirstStatus==1){
                    addedSteps = addedSteps - 1;
                }
            }
            
            
            steps = steps + addedSteps; // Create running total
            index++; // Move to next key
        }
        
        
        if (steps < finalSteps && steps != 0){ // Need to test if zero because No Keys(0000) produces a zero step output
            finalSteps=steps;
        }
        
    }
    
    cout << "Final Step Count: " << finalSteps << endl;
    
    
    return 0;
    
    
    
}