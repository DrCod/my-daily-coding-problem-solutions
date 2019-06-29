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
#include <cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<exception>
#include <algorithm>
#include <map>
#include <memory>
#include <list>





using namespace std;


struct{
    
    int data;
    node *next;
};

class ListNode{
    
private:
    node *head,*tail;
    ListNode(){
        head =NULL;
        tail =NULL;
    }
    
};











shared_ptr<list<int>> merge_sorted_linked_lists(shared_ptr<list<int>> L,shared_ptr<list<int>> F);
std::queue<int> arraySubsetProduct(vector<int> &arr);
bool sumAddUpToK(int k, vector<int> &num_list);
string intToString(int x);
int stringToInt(const string & s);
void reverse_strings(string* s );
void phone_mnemonic(const string &num);
void  phone_mnemonic_helper(const string &num,int d, string* ans);
int main(int argc, char** argv) {
    
    //vector<int> sample_arr ={10,15,3,7}; 
    string s;
   // string* sptr; 
    //cout<< "Enter a string to reverse it: ";
    list =
    cin>> s;
    //sptr =&s;
    phone_mnemonic(s);
    
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

/*Problem  2
 * Given an array of integers, return a new array such that each element 
 * at index i of the new array is the product of all the numbers in the 
 * original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would
 *  be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], 
 * the expected output would be [2, 3, 6].
 */

std::queue<int> arraySubsetProduct(vector<int> &arr){
    queue<int> q;
    int arr_size =arr.size();
    for(int i =0; i<arr_size;i++){
        
    if(arr_size <=1){
      q.push(arr[i]);
    }
   else{
       q.push(arr[i-1]* arr[i+1]);
  }
} 
    return q;
}

/*
 * P3
 * 
 Given a list of numbers and a number k, return whether 
 * any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17,
 *  return true since 10 + 7 is 17.
 */

bool sumAddUpToK(int k, vector<int> &num_list){
    bool result =false;
  
    vector<int> temp =num_list;
    
    for(int i = 0; i< num_list.size(); i++){
        
        result = temp.at(i) == k - num_list.at(i)? true: false;
    }
 return result;
}


/* 
 P4
 * 
 * Given the root to a binary tree, 
 * implement serialize(root), which serializes 
 * the tree into a string, and deserialize(s), 
 * which deserializes the string back into the tree.
 * 
 * 
 * Coming soon...
 */


/* 
 P5
 * 
 * Implement string/integer inter-conversion functions. Use the following 
 * function signatures: String intToString(int x) and int stringToInt(Strings)
 */

string intToString(int x){
    
    bool is_negative ;
    
    if( x< 0){
        x =-x;
        is_negative =true;
    }
    else{
        is_negative=false;
    }
    
    string s;
    while(x){
        s.push_back('0'+ x%10);
        x %= 10;
    }
    if (s.empty()){
        return {"0"}; //x is 0
    }
    
    if(is_negative){
        s.push_back('-');
    }
   reverse(s.begin(),s.begin());
    
    return s;
}

// We define the valid strings for this function as those matching regexp
// -?[0 -9]+.

int stringToInt(const string& s){
    // s starts with '-' but as valid integer

    if(s == "-"){
        throw invalid_argument("illegal input");
    }
    bool is_negative =s[0] == '-';
    int x =0;
    for( int i =is_negative ; i< s.size(); ++i){
        if(isdigit(s[i])){
            x =x *10 + s[i] -'0';
        }
        else{
             throw invalid_argument("illegal input");
        }
    }
    return is_negative? -x:x;
}

/*
 P6 Implementation of a function for reversing the words in a string s. This function takes 0(1) 
 * time complexity
 */

void reverse_strings(string* s ){
    
    //first -> revere the whole string
    reverse(s->begin(), s->end());
    size_t start =0,end;
    while((end = s->find(" ", start)) != string::npos){
        //now-> reverse each word in the string
        reverse(s->begin()+start,s->end() +end);
        start =end +1;
    }
    //reverse the last word.
    reverse(s->begin()+start,s->end());
    cout << "your reversed string is "<< *s; 
}

/*P7
 Write a function which takes as input a phone number, specified
as a string of digits, return all possible character sequences that correspond to the phone
number. The cell phone keypad is specified by a mapping M that takes a digit and returns
the corresponding set of characters. The character sequences do not have to be legal words or
phrases.
 */

void phone_mnemonic(const string &num){
    string ans(num.size(),0);
    phone_mnemonic_helper(num,0,&ans);
}

const int KNumTelDigits =10;
const array<string, KNumTelDigits> M ={{"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV",
                                       "WXYZ"
                                       }};

void  phone_mnemonic_helper(const string &num,int d, string* ans){
    if(d ==num.size()){
        cout<< *ans<<endl;
    }
    else{
        for (const char &c :M[num[d] -'0']){
            (*ans)[d] = c;
            phone_mnemonic_helper(num,d+1, ans);
        }
    }
}

/*
 
 Write a function that takes L and F, and returns the merge of L
and F. Your code should use O(1) additional storage—it should reuse the nodes from the
lists provided as input. Your function should use O(1) additional storage.
 *The only field you can change in a node is next.
 */

shared_ptr<ListNode> merge_sorted_linked_lists(shared_ptr<ListNode> L,shared_ptr<ListNode> F){
    shared_ptr<ListNode> sorted_head =nullptr, tail =nullptr;
    
    while(L&&F){
        append_node_and_advance(&sorted_head,&tail,L->d < F->data? &L:&F);
    }
 //append remaining nodes of F
    if(F){
        append_node(F,&sorted_head,&tail);
    }
    
  //append the remaining nodes of L 
    if(L){
       append_node(L,&sorted_head,&tail); 
    }
    
    return sorted_head;
} 

void append_node_and_advance(shared_ptr<ListNode>* head,shared_ptr<ListNode>* tail,shared_ptr<ListNode>* node){
    append_node(*node, head,tail);
    //advance node
    *node = (*node)->next;
}

void append_node(const shared_ptr<ListNode> &node,const shared_ptr<ListNode> *head,
        const shared_ptr<ListNode> *tail ){
    *head ? (*tail)->next = node: *head =node;
    *tail =node;// resets the tail to the last node;
}


/*
 Give a linear time nonrecursive function that reverses a singly linked list. 
 * The function should use no more than constant storage beyond that needed for the list
itself.
 */
// TWO APPROACHES
//the recursive approach using O(n) time complexity 

shared_ptr<ListNode<int>> reverse_linked_list(const shared_ptr<ListNode<int>> &head){
    
    if(!head || !head->next){
        return head;
    }
    
    shared_ptr<ListNode<int>> new_head =reverse_linked_list(head->next);
    
    head->next->next =head;
    head->next =nullptr;
    return new_head;
    
}


// Non-recursive solution using 2 pointers to traverse the list
//Uses O(1) additional storage and O(n) time complexity.

shared_ptr<ListNode<int>> reverse_linked_list(const shared_ptr<ListNode<int>> &head){

    shared_ptr<ListNode<int>> prev =nullptr, curr;

    while(curr){
        shared_ptr<ListNode<int>> temp = new shared_ptr<ListNode<int>>;
        curr->next =prev;
        prev =curr;
        curr= temp;
    }
    return prev;
}