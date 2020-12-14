#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int alice_score = 0;
        int bob_score = 0;
        bool flag = true;
        while (!stones.empty()) {
            if (flag) {
                vector<int> temp_alice(stones);
                int ahead_of_temp_alice = compute_score(temp_alice.erase(temp_alice.back()));
                int back_of_temp_alice = compute_score(temp_alice.erase(temp_alice.front()));

                // alice
                if (ahead_of_temp_alice > back_of_temp_alice) {
                    stones.pop_back();
                } else {
                    stones.erase(stones.begin());
                    //stones.pop_front();
                } // alice done
                // compute score
                alice_score += compute_score(stones);
                flag = false;
            }  else {
                int temp1 = stones.front();
                vector<int> temp1_vec(stones);
                temp1_vec.erase(temp1_vec.begin());
                int score1 = compute_score(temp1_vec);

                if (temp1 < score1 && temp1 > stones.back()) {
                    stones.erase(stones.begin());
                    bob_score += score1;
                } else {
                    stones.pop_back();
                    bob_score += compute_score(stones);
                }
                flag = true;
            }
        }

        return alice_score - bob_score;

    }
private:
    int compute_score(vector<int> stones) {
        int res = 0;
        for (int i = 0; i < stones.size(); i++) {
            res += stones[i];
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 不会不会啊
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    vector<int> stones = {5,3,1,4,2};
    Solution solution;
    int res = solution.stoneGameVII(stones);
    cout << res;

    return 0;
}

