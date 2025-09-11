-- Write your PostgreSQL query statement below
-- select teacher_id, subject_id from Teacher
-- group by teacher_id, subject_id;

select teacher_id, count(teacher_id) as cnt from(
    select teacher_id, subject_id from Teacher
    group by teacher_id, subject_id
)
group by teacher_id;