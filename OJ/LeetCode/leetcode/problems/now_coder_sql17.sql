# 题目描述
# 获取当前（to_date='9999-01-01'）薪水第二多的员工的emp_no以及其对应的薪水salary
# CREATE TABLE `salaries` (
#     `emp_no` int(11) NOT NULL,
#     `salary` int(11) NOT NULL,
#     `from_date` date NOT NULL,
#     `to_date` date NOT NULL,
#     PRIMARY KEY (`emp_no`,`from_date`)
# );
# 输入描述:
# 无
# 输出描述:
# emp_nosa    lary
# 
# 10009
# 
# 94409

select emp_no, salary
from salaries
where
  to_date = '9999-01-01'
  and
  salary = (select distinct salary from salaries order by salary desc limit 1, 1);

# 1. 不要将变量名写错！！！
