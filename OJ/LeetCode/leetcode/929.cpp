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
 *929. Unique Email Addresses
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

 

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 

Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
 */

/* my solution */
// solution-1, 36ms, defeat 43.47%
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (string email : emails) {
            string temp = "";
            bool flag = true;
            bool at_flag = false;
            for (char c : email) {
                if (c == '.' && !at_flag)
                    continue;
                if (c == '+')
                    flag = false;
                if (c == '@') {
                    flag = true;
                    at_flag = true;
                }
                if (flag)
                    temp += c;
            }
            s.insert(temp);
        }

        return s.size();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串数组,根据一些规则进行处理.
// 其实并不难,之前打开过这道题的页面,但是"感觉"有些麻烦,就跳过了...
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    vector<string> emails = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
    int res = solution.numUniqueEmails(emails);
    cout << res;

    return 0;
}

