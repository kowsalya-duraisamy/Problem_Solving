SELECT Department, Employee, Salary
FROM (
SELECT Emp.id,Emp.name AS Employee,Emp.salary AS Salary, Dept.name AS Department,
DENSE_RANK() over (PARTITION BY Emp.departmentId ORDER BY Emp.salary DESC) AS Salary_Rank
FROM Employee as Emp LEFT JOIN Department Dept
ON Emp.departmentId = Dept.id)AS TMP
WHERE Salary_Rank <= 3