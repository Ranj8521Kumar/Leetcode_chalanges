-- Write your PostgreSQL query statement below
select w1.id
from Weather w1
join Weather w2 
on w1.recordDate = w2.recordDate + interval '1 Day' -- Date Airthmetic is used for both mysql and postgresql
where w1.temperature > w2.temperature;