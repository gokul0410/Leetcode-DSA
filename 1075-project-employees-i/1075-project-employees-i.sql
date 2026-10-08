select p.project_id , round(AVG(e.experience_years),2) as average_years
from Project as p 
left join Employee as e on p.employee_id = e.employee_id
group by project_id;