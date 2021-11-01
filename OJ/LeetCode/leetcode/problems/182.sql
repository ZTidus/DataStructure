/* Leetcode-cn  */
/* Type: sql */
/* 题目信息 */
/*
 *182. 查找重复的电子邮箱
编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。

示例：

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
根据以上输入，你的查询应返回以下结果：

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
说明：所有电子邮箱都是小写字母。
 */

/* my solution */
-- solution-x, ms, defeat %
select Email from Person
group by Email -- 这一句如果没有就是错的，必须要有group by吗
having count(Email) >= 2;

/* better solution */
-- solution-x, ms, defeat %


/* 一些总结 */
-- 1. 题意: 
--
-- 需要注意的点: 
-- 1. 如果不使用 GROUP BY 子句，则 HAVING 的行为与 WHERE 子句一样。
-- 2. 
-- 3. 

