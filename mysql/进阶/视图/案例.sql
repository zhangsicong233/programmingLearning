-- 1、为了保证数据库表的安全性，开发人眼在操作 tb_user 表时，只能看到用户的基本字段，屏蔽手机号和邮箱两个字段
CREATE VIEW tb_user_view AS
SELECT
    id,
    name,
    profession,
    age,
    gender,
    status,
    createtime
FROM tb_user;

SELECT * FROM tb_user_view;

-- 2、查询每个学生所选修的课程（三表联查），在很多业务中都有使用，为了简化操作，定义一个视图
CREATE VIEW tb_stu_sourse_view AS
SELECT
    s.name student_name,
    s.no student_no,
    c.name course_name
FROM
    student s,
    student_course sc,
    course c
WHERE
    s.id = sc.studentid && sc.courseid = c.id;