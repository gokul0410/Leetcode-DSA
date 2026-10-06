select p.product_name , s.year , s.price
from Product as p 
left join sales as s on s.product_id = p.product_id
where s.year is not null and s.price is not null;