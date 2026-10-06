select e.name as name ,b.bonus as bonus
from Employee as e
left join Bonus as b on b.empId = e.empId 
where b.bonus < 1000 or b.bonus is null;