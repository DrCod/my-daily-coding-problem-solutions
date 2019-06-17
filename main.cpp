/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dronny
 *
 * Created on June 16, 2019, 9:05 AM
 */

#include<iostream>
#include <cstdlib>
#include<vector>

using namespace std;


int stairCase(int n);

int stairCaseSteps(int n,vector<int> &x);

int main(int argc, char** argv) {
    
    vector<int> arr ={1,3,5};
    int n;
    cout<< "Enter a number";
    cin>> n;    
    
    cout<< "There are "<<stairCaseSteps(n,arr)<<" ways to climb the staircase of "<<n<< "stairs";
    
    return 0;
}

/*
 *Problem 1
 *  There's a staircase with N steps, and you can climb
 *  1 or 2 steps at a time. Given N, write a function that
 *  returns the number of unique ways you can climb the staircase.
 *  The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

    1, 1, 1, 1
    2, 1, 1
    1, 2, 1
    1, 1, 2
    2, 2

What if, instead of being able to climb 1 or 2 steps at a time, 
you could climb any number from a set of positive integers X? 
 * For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time. 
 * Generalize your function to take in X. 
 */

/*
 To return the number of unique ways
 * 1 or 2 steps a time
 * For single number input
 */

int stairCase(int n){
    
    if (n<=1){
        return 1;
    }
    else{
        return (stairCase(n-1) + stairCase(n-2));
    }
    
}

/*
 For the second case where it takes an array of steps
 */

int stairCaseSteps(int n,vector<int> &x){
    vector<int> cache;
    for(int i=0; i< n;i++){
        cache[i] =0;
    }

    cache[0] =1;
    
    for( int j =1; j<=n+1;j++){
        vector<int> sum_vals_x;
        for (int v=0 ; v<x.size();v++){
            if(j-v >=0){
           
                sum_vals_x[v] =cache[j-v];
                
            }
        }
        int sumX =0;
        for(int k =0;k<sum_vals_x.size();k++){
            sumX =sumX + sum_vals_x[k];
        }
        
        cache[j] = cache[j] + sumX;
    }
    
    return cache[n];
}