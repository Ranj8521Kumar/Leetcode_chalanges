-- Write your PostgreSQL query statement below
select U.unique_id, E.name from EmployeeUNI U
right join Employees E on E.id = U.id;