# 题目描述
# 查找所有员工的last_name和first_name以及对应的dept_name，也包括暂时没有分配部门的员工
# CREATE TABLE `departments` (
#     `dept_no` char(4) NOT NULL,
#     `dept_name` varchar(40) NOT NULL,
#     PRIMARY KEY (`dept_no`)
# );
# CREATE TABLE `dept_emp` (
#     `emp_no` int(11) NOT NULL,
#     `dept_no` char(4) NOT NULL,
#     `from_date` date NOT NULL,
#     `to_date` date NOT NULL,
#     PRIMARY KEY (`emp_no`,`dept_no`)
# );
# CREATE TABLE `employees` (
#     `emp_no` int(11) NOT NULL,
#     `birth_date` date NOT NULL,
#     `first_name` varchar(14) NOT NULL,
#     `last_name` varchar(16) NOT NULL,
#     `gender` char(1) NOT NULL,
#     `hire_date` date NOT NULL,
#     PRIMARY KEY (`emp_no`)
# );
# 
# output: last_name first_name dept_name      

select e.last_name, e.first_name, de.dept_name
from employees as e
left join dept_emp as d on e.emp_no = d.emp_no
left join departments as de on d.dept_no = de.dept_no;

# 1. 本题是三个表，其中两对left join
      
