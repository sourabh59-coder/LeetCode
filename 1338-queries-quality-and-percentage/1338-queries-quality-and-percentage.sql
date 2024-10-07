SELECT
query_name,ROUND((AVG(rating/position)),2) as quality, ROUND(SUM(IF(rating < 3, 1, 0))/COUNT(*)*100,2) as poor_query_percentage
FROM
Queries
WHERE query_name is NOT NULL
GROUP BY query_name
