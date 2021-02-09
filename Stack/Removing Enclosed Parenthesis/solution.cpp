/*
    Copyright (C) 2021, Sathira Silva
    
    Problem Statement: You are given a string s containing valid number of brackets "(", ")" and lowercase alphabet characters. Return the string after removing all outermost
    brackets that enclose the whole string.
*/

#include <bits/stdc++.h>

using std;

string solve(string s) {
    stack<int> st;                      // Stack to keep track of not-yet-closed-left-paranthesis
    vector<int> pairs(s.length(), -1);  // Vector to keep track of indices of corresponding right paranthesis for left paranthesis

    // Go through the string to find the paranthesis pairs
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            pairs[st.top()] = i;
            st.pop();
        }
    }
    
    // Using two pointer technique to build the resulting string
    int start, end = s.length();

    // If the character at starting index is a left paranthesis and the character at ending index is its right pair, move both pointers to right and left by 1 step
    // (Remove the outermost parantheses pairs)
    for (start = 0; start < end && s[start] == '(' && pairs[start] == end - 1; start++, end--);

    return s.substr(start, end - start);
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
}
