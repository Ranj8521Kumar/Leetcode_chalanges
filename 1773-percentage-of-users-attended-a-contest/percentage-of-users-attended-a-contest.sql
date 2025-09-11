-- Write your PostgreSQL query statement below
select contest_id, round(count(user_id)*100.0/(select count(u.user_id) from Users u), 2) as percentage from Register
group by contest_id
order by percentage desc, contest_id asc;