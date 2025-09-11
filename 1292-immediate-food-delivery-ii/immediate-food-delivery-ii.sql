-- Write your PostgreSQL query statement below
-- select distinct on (customer_id)
--     customer_id, 
--     order_date, 
--     customer_pref_delivery_date,
--     case
--         when order_date = customer_pref_delivery_date then 'immediate' else 'Schedule' end as status
-- from Delivery
-- order by customer_id, order_date;



select round(count(*) filter (where a.status = 'immediate')*100.00/count(a.customer_id), 2) as immediate_percentage from (
    select distinct on (customer_id)
    customer_id, 
    order_date, 
    customer_pref_delivery_date,
    case
        when order_date = customer_pref_delivery_date then 'immediate' else 'Schedule' end as status
from Delivery
order by customer_id, order_date
) a;