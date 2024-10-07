Select
r.contest_id, ROUND(COUNT(r.user_id)/(SELECT COUNT(DISTINCT user_id) from Users)*100,2) as percentage
from
register as r
group by r.contest_id
ORDER BY
percentage DESC, r.contest_id ASC