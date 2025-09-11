-- Write your PostgreSQL query statement below
-- select to_char(trans_date, 'YYYY-MM') from Transactions;

select 
    to_char(trans_date, 'YYYY-MM') as month, 
    country, 
    count(id) as trans_count, 
    count(id) filter (where state = 'approved') as approved_count,
    sum(amount) as trans_total_amount,
    coalesce(sum(amount) filter (where state = 'approved'), 0) as approved_total_amount
from Transactions
group by month, country;