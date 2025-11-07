/* 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters. */



class Solution {
    void getCombination(string digits, vector<string>& ans, string temp, int id,
                        string container[]) {
        if (id == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int num = digits[id] - '0';

        string value = container[num];

        for (int i = 0; i < value.size(); i++) {

            getCombination(digits, ans, temp + value[i], id+1, container);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        int id = 0;
        string container[] = {"", "", "abc", "def","ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
        getCombination(digits, ans, temp, id, container);
        return ans;
    }
};