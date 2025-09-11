-- Write your PostgreSQL query statement below

-- Every students is listed with every pairs:

-- select s.student_id, s.student_name, sub.subject_name
-- from Students s
-- cross join Subjects sub
-- order by s.student_id, s.student_name;

-- Count exam attendances:

-- select student_id, subject_name, count(*)
-- from Examinations
-- group by student_id, subject_name
-- order by student_id;


-- Now final for getting count of every studet in every exam:

select ss.student_id, ss.student_name, ss.subject_name, coalesce(e.attended_exams, 0) as attended_exams --select first non-null value, so use coalesce
from (
    select s.student_id, s.student_name, sub.subject_name
    from Students s
    cross join Subjects sub
) ss
left join (select student_id, subject_name, count(*) as attended_exams
    from Examinations
    group by student_id, subject_name
) e
on ss.student_id = e.student_id and ss.subject_name = e.subject_name
order by ss.student_id, ss.subject_name;