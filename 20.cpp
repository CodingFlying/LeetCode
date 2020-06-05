#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        map<char, char> dict;
        dict.insert(map<char, char>::value_type(')', '('));
        dict.insert(map<char, char>::value_type(']', '['));
        dict.insert(map<char, char>::value_type('}', '{'));

        stack<char> mystack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                mystack.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (mystack.empty()) return false;
                if (dict[s[i]] == mystack.top()) {
                    mystack.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        if(mystack.empty()) return true;
        else return false;
    }
};

int main() {
    string s = "[([])]";
    Solution s1;
    bool val = s1.isValid(s);
    cout << val << " ";
}