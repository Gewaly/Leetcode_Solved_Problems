# Write your MySQL query statement below
#SELECT user_id,  UPPER(LEFT(name,1)+LOWER(SUBSTRING(name,2,LEN(name)))

#SELECT UPPER(LEFT(word,1))+LOWER(SUBSTRING(word,2,LEN(word))) FROM [yourtable]
#FROM Users

SELECT 
user_id,
concat(upper(substr(name,1,1)),lower(substr(name,2))) as name
FROM Users
ORDER BY user_id ASC ;