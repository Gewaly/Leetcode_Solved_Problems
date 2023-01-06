# Write your MySQL query statement below
SELECT user_id AS buyer_id, join_date, IFNULL(orders_in_2019, 0) AS orders_in_2019
FROM users 
LEFT JOIN ( SELECT buyer_id, COUNT(order_id) AS orders_in_2019 
            FROM orders
            WHERE year(order_date) = 2019
            GROUP BY buyer_id ) A
ON users.user_id = A.buyer_id