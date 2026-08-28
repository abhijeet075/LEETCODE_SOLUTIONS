# Write your MySQL query statement below
select s.name from SalesPerson s
left join Orders o on s.sales_id = o.sales_id
left join Company c
on o.com_id =c.com_id 
GROUP BY s.sales_id , s.name having count(case when c.name = 'RED' then 1 END)=0;