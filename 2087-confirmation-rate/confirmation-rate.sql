-- Write your PostgreSQL query statement below


-- select a.user_id, count(a.user_id) as confirmation_message,
-- coalesce(b.confirmed_action, 0) as confirmed_action from Confirmations a
-- left join (
--     select user_id, count(*) as confirmed_action
--     from Confirmations
--     where action = 'confirmed'
--     group by user_id
-- ) b on a.user_id = b.user_id
-- group by a.user_id, b.confirmed_action;


select aa.user_id, round(coalesce(c.confirmed_action*1.0/nullif(c.confirmation_message, 0), 0), 2) as confirmation_rate
from Signups aa
left join (
    select a.user_id, count(a.user_id) as confirmation_message,
    coalesce(b.confirmed_action, 0) as confirmed_action from Confirmations a
    left join (
        select user_id, count(*) as confirmed_action
        from Confirmations
        where action = 'confirmed'
        group by user_id
    ) b on a.user_id = b.user_id
    group by a.user_id, b.confirmed_action
) c on aa.user_id = c.user_id;