#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (nums[size - 1] < target) {
            return size;
        }
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] == target) {
                return mid;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 7, 8, 9};
    Solution s1;
    int a = s1.searchInsert(nums, 6);
    cout << a <<endl;
    return 0;
}