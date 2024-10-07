# Write your MySQL query statement below
Select 
p.product_id, IF(ROUND((SUM(p.price*u.units)/SUM(u.units)),2) is NULL, 0, ROUND((SUM(p.price*u.units)/SUM(u.units)),2)) as average_price 
From 
Prices as p
LEFT JOIN 
UnitsSold as u
ON
(p.product_id = u.product_id AND u.purchase_date between p.start_date AND p.end_date)
GROUP BY 
p.product_id;