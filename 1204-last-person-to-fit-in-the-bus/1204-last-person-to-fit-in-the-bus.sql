# Write your MySQL query statement below
select person_name from(SELECT * ,
        SUM(weight) OVER (ORDER BY turn) total_weight 
        FROM queue) y  where total_weight <=1000 
        order by total_weight desc 
        limit 1;