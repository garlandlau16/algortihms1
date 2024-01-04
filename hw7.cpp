// Garland Lau
// 11/1/2023
// CPSC 4100
// hw7.cpp
//
// Homework 7
// 1) Palindrome
// 2) Special Fibonacci Sequence
// 3) Find football scoreboard from number of pushups

#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

// A string is a palindrome if there is 1 or less differences
bool findPalindrome(string palin_test);

// Find the nth fibonacci number given the first 3 numbers in 
// the fibonacci sequence (f0, f1, f2)
long int fib_seq(long int f0, long int f1, long int f2, long int n);

// A cheerleader squad does psuhups everytime the football team scores.
// Given the number of pushups and number of scoring plays, we find the
// highest score possible for their football team. 
int findScore(int pushups, int score, int total, int m, vector<int>& s);

int main(){
    // Palindrome test cases
    string palin_t1 = "aba"; // True
    string palin_t2 = "abca"; // True
    string palin_t3 = "abcd"; // False
    // Palindrome answeres
    bool palin_a1 = findPalindrome(palin_t1);
    bool palin_a2 = findPalindrome(palin_t2);
    bool palin_a3 = findPalindrome(palin_t3);

    // Fibonnaci test casses
    // int fib_t1[4] = {f[0], f[1], f[2], nth number in fib_seq}
    long int fib_t1[4] = {1, 1, 1, 4}; // 11
    long int fib_t2[4] = {1, 2, 3, 5}; // 48
    long int fib_t3[4] = {1, 3, 5, 5}; // 76
    string str_fib_t1 = "{1, 1, 1, 4}"; 
    string str_fib_t2 = "{1, 2, 3, 5}"; 
    string str_fib_t3 = "{1, 3, 5, 5}"; 

    // Fibonacci answers
    long int fib_a1 = fib_seq(fib_t1[0], fib_t1[1], fib_t1[2], fib_t1[3]);
    long int fib_a2 = fib_seq(fib_t2[0], fib_t2[1], fib_t2[2], fib_t2[3]);
    long int fib_a3 = fib_seq(fib_t3[0], fib_t3[1], fib_t3[2], fib_t3[3]);
    
    // Football score test cases
    // int score_t1[5] = {total points, number of scoring plays, 
    //  points for touchdown, pts for field goal, pts for safety}
    int score_t1[5] = {29, 3, 7, 3, 2}; //14 (3, 2, 2, 7)
    int score_t2[5] = {7, 3, 7, 3, 2}; // 7 (7)
    int score_t3[5] = {32, 3, 7, 3, 2}; //16 (7, 2, 7)
    vector <int> sc_method(3);
    sc_method[0] = 7;
    sc_method[1] = 3;
    sc_method[2] = 2;
    
    // Football score answers
    int score_a1 = findScore(0, 0, 29, 3, sc_method); 
    int score_a2 = findScore(0, 0, 7, 3, sc_method);
    int score_a3 = findScore(0, 0, 32, 3, sc_method);

    cout << "Palindrome test cases: " << endl;
    cout << palin_t1 << ": " << palin_a1 << endl;
    cout << palin_t2 << ": " << palin_a2 << endl;
    cout << palin_t3 << ": " << palin_a3 << endl << endl;
    
    cout << "Fibonacci sequence test cases: " << endl;
    cout << str_fib_t1 << ": " << fib_a1 << endl;
    cout << str_fib_t2 << ": " << fib_a2 << endl;
    cout << str_fib_t3 << ": " << fib_a3 << endl << endl;
    

    cout << "Football Socre test cases: " << endl;
    cout << score_t1[0] << ": " << score_a1 << endl;
    cout << score_t2[0] << ": " << score_a2 << endl;
    cout << score_t3[0] << ": " << score_a3 << endl << endl;
       
    return 0;
}

bool findPalindrome(string palin_test){
    bool isPalin = false;
    int num_diff = 0;
    int p_length, l, r; //Palindrome length, left pointer, right pointer

    p_length = palin_test.length();
    l = 0;
    r = p_length - 1;

    // Only 1 difference is allowed to be considered a palindrome.
    // If there is a difference, it's skipped over so left and right
    // pointers still point to the same letter
    while(l <= r){
        if(palin_test[l] != palin_test[r]){
            num_diff += 1;
            if(palin_test[l] == palin_test[r-1]){
                r = r-1;
            }else if(palin_test[l+1] == palin_test[r]){
                l = l+1;
            }
        }
        l += 1;
        r -= 1;
    }

    if(num_diff <= 1){
        isPalin = true;
    }

    return isPalin;
}

long int fib_seq(long int f0, long int f1, long int f2, long int n){
    long int answer;
    long int fib[n];

    fib[0] = f0;
    fib[1] = f1;
    fib[2] = f2;

    for(long int i = 3; i <= n; i++){
        fib[i] = fib[i-1] + 2*fib[i-2] + 3*fib[i-3];
    }

    answer = fib[n];
    return answer;
}

int findScore(int pushups, int score, int total, int m, vector<int>& s){
    int maxScore = 0;
    if(pushups > total){
        return 0;
    }
    else if(pushups == total){
        return score;
    }else{
        for(int i = 0; i < m; i++){
            maxScore = max(findScore(pushups + s[i] + score, score + s[i], total, m, s), maxScore);
        }
        return maxScore;
    }
}