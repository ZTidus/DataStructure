/* Leetcode-cn  */
/* Type: sql */
/* 题目信息 */
/*
 *1517. 查找拥有有效邮箱的用户
用户表： Users

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar | 
+---------------+---------+
user_id （用户 ID）是该表的主键。
这个表包含用户在某网站上注册的信息。有些邮箱是无效的。
 

写一条 SQL 语句，查询拥有有效邮箱的用户。

有效的邮箱包含符合下列条件的前缀名和域名：

前缀名是包含字母（大写或小写）、数字、下划线 '_'、句点 '.' 和/或横杠 '-' 的字符串。前缀名必须以字母开头。
域名是 '@leetcode.com' 。
按任意顺序返回结果表。

 

查询格式如下所示：

Users
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+

结果表：
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
2 号用户的邮箱没有域名。
5 号用户的邮箱包含非法字符 #。
6 号用户的邮箱的域名不是 leetcode。
7 号用户的邮箱以句点（.）开头。
 */


/* my solution */
-- solution-x, ms, defeat %


/* better solution */
-- solution-x, ms, defeat %
select * from users
where mail regexp '^[a-zA-Z][a-zA-Z0-9\_\\./-]*@leetcode\.com$';

-- 或者下面这一种
# Write your MySQL query statement below
select * from users
where mail regexp '^[a-zA-Z][\\w\\./-]*@leetcode\.com$';
/* 一些总结 */
-- 1. 题意: 
--
-- 需要注意的点: 
-- 1. 正则表达式的运用
-- 2. regexp
-- 3. \w 匹配字母或数字或下划线或汉字 等价于 '[^A-Za-z0-9_]'。
-- \s 匹配任意的空白符
-- \d 匹配数字
-- \b 匹配单词的开始或结束
-- ^ 匹配字符串的开始
-- $ 匹配字符串的结束
