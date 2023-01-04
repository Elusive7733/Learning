SELECT student.name, student.id
From Student
FULL Outer JOIN
    StudentHasCourses
    ON Student.id = StudentHasCourses.student_id
    Full Outer Join Course
    ON StudentHasCourses.course_id = Course.id
WHERE Course.name = "Programming";