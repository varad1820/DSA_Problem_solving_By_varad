---
20. Valid Parentheses
Solved
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


---
class Solution {
public:
    bool isValid(string s) {
        stack<int> box;
        int n = s.size();

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                box.push(c);
            } else {

                if (box.empty())
                    return false;
                char t = box.top();
                box.pop();
                if ((c == ')' && t != '(') || (c == ']' && t != '[') ||
                    (c == '}' && t != '{'))
                    return false;
            }
        }

        return box.empty();
    }
};