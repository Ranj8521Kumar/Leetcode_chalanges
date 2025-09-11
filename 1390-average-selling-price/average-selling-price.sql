-- Write your PostgreSQL query statement below
select p.product_id, round(coalesce(sum(p.price*u.units)*1.0/sum(u.units), 0), 2) as average_price from Prices  p
left join UnitsSold u
on p.product_id = u.product_id
    and purchase_date >= start_date and purchase_date <= end_date
group by p.product_id;


-- select * from Prices  p
-- left join UnitsSold u
-- on p.product_id = u.product_id
--     and purchase_date >= start_date and purchase_date <= end_date