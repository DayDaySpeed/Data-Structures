#include "CurrentDemo.h"
#if DEMO == LONGESTCONSECUTIVESUBSEQUENCE

#include <vector>
#include <unordered_set>
#include <algorithm>   // for std::max
#include <iostream>    // for std::cout

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            //先判断有没有num-1，有则退出
            if (!num_set.count(num - 1)) {
                //没有num-1后，将当前num设置为起始，并置当前连续长度为1
                int currentNum = num;
                int currentStreak = 1;
				//循环寻找,时间复杂度为O(n)
                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    int result = sol.longestConsecutive(nums);
    cout << "The length of the longest consecutive sequence is: " << result << endl;
    return 0;
}

#endif // DEMO == LONGESTCONSECUTIVESEQUENCE