# Write your MySQL query statement below
SELECT  A1.id FROM
Weather A1 ,Weather A2
WHERE A1.Temperature > A2.Temperature
AND DATEDIFF(A1.recordDate, A2.recordDate) = 1
;