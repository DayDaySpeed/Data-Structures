#include "CurrentDemo.h"
#if DEMO==GROUPANAGRAMS
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <numeric>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
                });
            };
		// 使用自定义哈希函数创建 unordered_map
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
		// 遍历每个字符串，统计字符出现次数，并将其分组
        for (string& str : strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a']++;
            }
			mp[counts].emplace_back(str);//将字符串添加到对应的分组中
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};




int main()
{
    Solution sol;
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

    vector<vector<string>> result = sol.groupAnagrams(strs);

    // 打印结果
    cout << "字母异位词分组结果：" << endl;
    for (const auto& group : result)
    {
        cout << "[ ";
        for (const string& s : group)
        {
            cout << s << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}






#endif // DEMO==GROUPANAGRAMS
