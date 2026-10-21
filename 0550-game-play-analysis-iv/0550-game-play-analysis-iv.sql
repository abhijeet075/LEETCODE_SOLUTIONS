select Round(count(distinct a.player_id)/
    (select count(distinct player_id) from activity),2
)  as fraction from activity a 
join(
    select player_id,min(event_date) as first_login 
    from activity  group by player_id
) as b 
on a.player_id = b.player_id
where datediff(a.event_date,b.first_login) =1;