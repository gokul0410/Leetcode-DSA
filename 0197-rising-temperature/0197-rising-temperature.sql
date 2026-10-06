select curr.id from 
weather as curr , weather as prev 
where datediff(curr.recordDate , prev.recordDate) = 1 and curr.temperature>prev.temperature;