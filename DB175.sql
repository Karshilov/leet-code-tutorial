/* Write your PL/SQL query statement below */
SELECT p.FirstName, p.LastName, a.City, a.State
FROM Person p
Left OUTER JOIN Address a
ON a.PersonId = p.PersonId