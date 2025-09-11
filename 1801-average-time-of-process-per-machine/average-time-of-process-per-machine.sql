-- Write your PostgreSQL query statement below
-- select s.machine_id, round(avg(e.timestamp - s.timestamp)::numeric, 3) as processing_time
-- from Activity s
-- join Activity e
-- on s.machine_id = e.machine_id
--     AND s.process_id = e.process_id
--     AND s.activity_type = 'start'
--     AND e.activity_type = 'end'
-- group by s.machine_id;



-- Another Approach:
select s.machine_id, round(avg(e.timestamp - s.timestamp)::numeric, 3) as processing_time
from Activity s
join Activity e
on s.machine_id = e.machine_id
    And s.process_id = e.process_id
    where s.activity_type = 'start' and e.activity_type = 'end'
group by s.machine_id