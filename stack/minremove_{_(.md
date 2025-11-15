---
1249. Minimum Remove to Make Valid Parentheses
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


---


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                count++;
            if (s[i] == ')' ){
                if(count != 0 ){
                    count--;
                }
                else{
                    s[i] = '_';
                }
            }                
        }

        int i = s.size()-1;

        while ( i >= 0 && count != 0) {
            if(s[i] == '(' ){
                s[i] = '_';
                count--;
            }
            i--;
        }

        string ans;
        ans.reserve(s.size());
        for (char c : s) {
            if (c != '_') ans.push_back(c);
        }

        return ans;
    }
};