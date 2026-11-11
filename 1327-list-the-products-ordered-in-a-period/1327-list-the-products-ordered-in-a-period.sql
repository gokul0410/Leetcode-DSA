select p.product_name as product_name , sum(o.unit) as unit
from Products p 
join Orders o using (product_id)
where year(o.order_date)='2020' and month(o.order_date)='02'
group by p.product_id 
having sum(o.unit)>=100;