# Write your MySQL query statement below
 select id, COUNT(*) as num

 from (
    select requester_id as  id from RequestAccepted
    union all
    select accepter_id as id from RequestAccepted
 ) x

 group by id order by num desc limit 1