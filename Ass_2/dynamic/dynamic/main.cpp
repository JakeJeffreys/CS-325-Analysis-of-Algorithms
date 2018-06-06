#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;


int main(){
    
    //long int quotient;
    
    int Array [9] = {2,1,2,0,1,1,0,2,1};
    int arraySize = 9;
    
    int numberOfKeys=3;
    int numberOfBalls=4;
    
    int keyArray[numberOfKeys];
    int ballArray[numberOfBalls];
    
    //int keysUsed;
    
    int finalSteps=1000;
    int index;
    
    
    // Find key array
    index=0;
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
    
    
    
    // Initialize variables
    int lKey,lBall;
    int steps=0;
    int nextKey;
    int rightMostBall;
    int leftMostBall;
    int addedSteps=0;
    
    lKey = keyArray[0];
    lBall = ballArray[0];
    
    int difference;
    int leftDistance;
    int rightDistance;
    int usedFirstStatus=0;
    int noNextKeyStatus=0;
    int tieStatus=0;
    int tieCounter=0;
    int markedKey =-1;
    int markedKeyPoint = 0;
    int markedKeyStatus=0;
    int rightNotUsed=-1;
    
    // Test balls on left of first key
    if ( lKey > lBall){
        difference = lKey-lBall;
        steps=difference+1;
        usedFirstStatus=1;
        cout << "Added Steps(pre): " << steps <<endl;
    }
    
    // Find next keys
    index=0;
    while (index < numberOfKeys){
        addedSteps=0;
        
        lKey = keyArray[index];
        cout << "Left Key: " << lKey << endl;
        
        // Test if there is a key to the right of current key
        if ( index == numberOfKeys-1){
            nextKey = arraySize+arraySize;
            cout << "NO NEXT KEY" << endl;
            noNextKeyStatus =1;
        } else {
            nextKey = keyArray[index+1]; //
        }
        cout << "Right Key: " << nextKey << endl;
        
        
        // Right most ball location (if it exists)
        rightMostBall = lKey; // Initializes right most ball location
        for (int a=0 ; a<numberOfBalls ; a++){
            if ( ballArray[a] > lKey && ballArray[a] < nextKey){
                rightMostBall = ballArray[a];
            }
        }
        cout << "Right Most Ball: " << rightMostBall << endl;
        
        // Left most ball
        leftMostBall = nextKey; // Initialize
        for (int a=numberOfBalls ; a>=0 ; a--){
            if ( ballArray[a]>lKey && ballArray[a]<nextKey){
                leftMostBall = ballArray[a];
            }
        }
        cout << "Left Most Ball: " << leftMostBall << endl;
        
        
        // Testing Distances
        //tieStatus=0;
        leftDistance = rightMostBall-lKey;
        rightDistance = nextKey-leftMostBall;
        
        cout << "Marked Key: " << markedKey << endl;
        
        
        if ( (rightMostBall-lKey) != 0 ) { // Test if ball was detected in range
            
            // Check if key is reused after tie
            if (tieStatus==1){
                markedKeyStatus=1;
            }
            
            // Compare distances
            if (leftDistance>rightDistance) {
                addedSteps = rightDistance+1;
                rightNotUsed=0;
                tieCounter=0;
                cout << "RIGHT CHOSEN" << endl;
            } else if (rightDistance>leftDistance){
                addedSteps = leftDistance+1;
                rightNotUsed=1;
                tieCounter=0;
                cout << "LEFT CHOSEN" << endl;
            } else { //Equal
                addedSteps = rightDistance+1;
                rightNotUsed=1;
                tieStatus=1;
                tieCounter++;
                markedKey = nextKey;
                cout << "TIE(s) FOUND --> " << tieCounter << endl;
            }
            
            // Test so we dont count first locker twice
            if (index==0 && usedFirstStatus==1){
                addedSteps = addedSteps - 1;
            }
            
            
            // Test so we dont reuse other lockers
            if (markedKeyStatus==1 && rightNotUsed==1) {
                    markedKeyPoint=1;
            }
            
            // Test if second tie
            if (tieCounter == 2){
                markedKeyPoint--;
                tieStatus=0;
                cout << "SECOND TIE FOUND" << endl;
            }
            
            
            
            
        }
        
        
        cout << "Point for tie: -" << markedKeyPoint << endl;
        addedSteps = addedSteps-markedKeyPoint;
        markedKeyPoint=0;
        
        
        cout << "Added Steps: " << addedSteps << endl;
        steps = steps + addedSteps; // Create running total
        index++; // Move to next key
        
        cout << endl;
    }
    
    if (steps < finalSteps && steps != 0){ // Need to test if zero because No Keys(0000) produces a zero step output
        finalSteps=steps;
    }
    
    //}
    
    cout << "Final Step Count: " << finalSteps << endl;
    
    
    return 0;
    
    
    
}