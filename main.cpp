#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/island-perimeter/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int per = 0;
        if (grid.empty()) return 0;
        int rs = grid.size();
        int cs = grid[0].size();
        for (int r = 0; r < rs; ++r) {
            for (int c = 0; c < cs; ++c) {
                if (grid[r][c]) {
                    if (r == 0 || !grid[r-1][c])
                        ++per;
                    if ((r == rs - 1) || !grid[r+1][c])
                        ++per;
                    if ((c == cs - 1) || !grid[r][c+1])
                        ++per;
                    if ((c == 0) || (!grid[r][c-1]))
                        ++per;
                }
            }
        }
        return per;
    }
};

void test1() {
    vector<vector<int>> v1{
            vector<int>{0, 1, 0, 0},
            vector<int>{1, 1, 1, 0},
            vector<int>{0, 1, 0, 0},
            vector<int>{1, 1, 0, 0}
    };

    cout << "16 ? " << Solution().islandPerimeter(v1) << endl;
}

void test2() {

}

void test3() {

}