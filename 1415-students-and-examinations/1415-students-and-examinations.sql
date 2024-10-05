SELECT 
s.student_id, s.student_name,su.subject_name,COUNT(e.subject_name) as attended_exams
FROM 
Students s
JOIN
Subjects su
LEFT JOIN
Examinations e
ON 
su.subject_name = e.subject_name AND s.student_id = e.student_id
GROUP BY s.student_id, s.student_name, su.subject_name 
ORDER BY s.student_id, su.subject_name;