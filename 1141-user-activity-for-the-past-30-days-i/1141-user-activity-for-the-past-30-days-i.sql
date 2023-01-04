# Write your MySQL query statement below
SELECT activity_date AS day, count(distinct user_id) AS active_users 
FROM Activity
WHERE activity_date BETWEEN date_sub('2019-07-27', INTERVAL 29 day) AND '2019-07-27'
GROUP BY activity_date;