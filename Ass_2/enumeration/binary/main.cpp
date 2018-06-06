#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;


int main(){
    
    long int quotient;
    
    int Array[9] = {2,1,0,0,2,0,0,2,1};
    
    int arraySize = 9;
    
    int numberOfKeys=3;
    int numberOfBalls=2;
    
    int binaryArray[numberOfKeys];
    int numCombinations = pow(2,numberOfKeys);
    
    int keyArray[numberOfKeys];
    int ballArray[numberOfBalls];
    int index=0;
    int keysUsed;
    
    int finalSteps=1000;
    
    
    // Find key array
    for ( int a=0 ; a<arraySize ; a++){
        if (Array[a] == 2){
            keyArray[index++] = a;
        }
    }
    cout << "Key Index: ";
    for(int j=0 ; j<numberOfKeys ; j++ )
        cout << keyArray[j];
    cout << endl;
    
    // Find ball array
    index=0;
    for ( int a=0 ; a<arraySize ; a++){
        if (Array[a] == 1){
            ballArray[index++] = a;
        }
    }
    cout << "Ball Array: ";
    for(int j=0 ; j<numberOfBalls ; j++ )
        cout << ballArray[j];
    cout << endl;
    
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
            rightMostBall = lKey; // Initializes right most ball location
            for (int a=0 ; a<numberOfBalls ; a++){
                if ( ballArray[a] > lKey && ballArray[a] < nextKey){
                    rightMostBall = ballArray[a];
                }
            }
            
            // Test if ball was detected in range
            if ( (rightMostBall-lKey) != 0 ) {
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