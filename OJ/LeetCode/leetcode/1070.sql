/* Leetcode-cn sql */
/* Type: sql */
/* 题目信息 */
/*
 *1070. 产品销售分析 III

销售表 Sales：

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
sale_id 是此表的主键。
product_id 是产品表的外键。
请注意，价格是按每单位计的。
产品表 Product：

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id 是此表的主键。
 

编写一个 SQL 查询，选出每个销售产品的 第一年 的 产品 id、年份、数量 和 价格。

查询结果格式如下：

Sales table:
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+ 
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+

Product table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+

Result table:
+------------+------------+----------+-------+
| product_id | first_year | quantity | price |
+------------+------------+----------+-------+ 
| 100        | 2008       | 10       | 5000  |
| 200        | 2011       | 15       | 9000  |
+------------+------------+----------+-------+

 */

/* my solution */
-- solution-x, ms, defeat %


/* better solution */
-- solution-x, ms, defeat %
select product_id, `year` as first_year, quantity, price
from sales
where (product_id, year) in 
    (select product_id, min(year) from sales group by product_id)

/* 一些总结 */
-- 1. 题意: 
--
-- 需要注意的点: 
-- 1. where后边的匹配要注意一下
-- 2. 
-- 3. 

