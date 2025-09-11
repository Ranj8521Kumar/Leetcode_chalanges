-- Write your PostgreSQL query statement below
-- select query_name, round(sum(rating*1.0/position)/count(query_name), 2) as quality, round(sum(case when rating < 3 then 1 else 0 end)*100.0/count(query_name), 2) as poor_query_percentage
-- from Queries
-- group by query_name;


select query_name, round(sum(rating*1.0/position)/count(query_name), 2) as quality, round(count(*) filter (where rating < 3)*100.0/count(query_name), 2) as poor_query_percentage
from Queries
group by query_name;
