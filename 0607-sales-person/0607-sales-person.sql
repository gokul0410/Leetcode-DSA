select s.name from salesPerson as s
where s.name not in (
    select s.name from salesPerson as s
    left join Orders as o on o.sales_id = s.sales_id
    left join Company as c on c.com_id = o.com_id 
    where c.name ="RED"
)
