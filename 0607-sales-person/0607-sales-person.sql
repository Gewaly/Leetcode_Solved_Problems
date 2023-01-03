# Write your MySQL query statement below

SELECT name
FROM salesperson
WHERE salesperson.sales_id not in 
(SELECT orders.sales_id FROM  orders
    Left JOIN company 
       on orders.com_id = company.com_id
WHERE 
  company.name = 'RED')