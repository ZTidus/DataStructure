/* Leetcode-cn  */
/* Type: sql */
/* 题目信息 */
/*
 *1350. 院系无效的学生
 */

/* my solution */
-- solution-x, ms, defeat %
select id, name
from students
where department_id not in 
(select id from departments)

/* better solution */
-- solution-x, ms, defeat %


/* 一些总结 */
-- 1. 题意: 
--
-- 需要注意的点: 
-- 1. 
-- 2. 
-- 3. 

