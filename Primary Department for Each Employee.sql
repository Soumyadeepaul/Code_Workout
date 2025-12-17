--https://leetcode.com/problems/primary-department-for-each-employee/description/?envType=study-plan-v2&envId=top-sql-50

--# Write your MySQL query statement below

select employee_id, department_id from employee where primary_flag = 'Y' 
union all
select employee_id, department_id from employee where primary_flag = 'N' and employee_id not in (select employee_id from employee where primary_flag='Y')
