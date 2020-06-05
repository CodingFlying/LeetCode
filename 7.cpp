#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int pop = x % 10; 
            // ans = ans*10 + pop;      //注意
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            ans = ans*10 + pop; 
            x /= 10;
        }
        return ans;
    }
};

int main() {
    Solution s1;
    int a = s1.reverse(-505);
    cout << a << endl;
}