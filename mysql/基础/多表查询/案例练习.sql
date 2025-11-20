-- 1、查询员工的姓名、年龄、职位、部门信息
SELECT e.name, e.age, e.job, d.name
FROM emp e
    INNER JOIN dept d ON e.dept_id = d.id;

-- 2、查询年龄小于 30 岁的员工姓名、年龄、职位、部门信息
SELECT e.name, e.age, e.job, d.*
FROM emp e
    INNER JOIN dept d ON e.dept_id = d.id
WHERE
    e.age < 30;

-- 3、查询拥有员工的部门 ID、部门名称
SELECT DISTINCT
    d.id,
    d.name
FROM dept d
    INNER JOIN emp e ON d.id = e.dept_id;
-- 错误总结：忘记了去重可以使用 distinct

-- 4、查询所有年龄大于 40 岁的员工，及其归属的部门名称；如果员工没有分配部门，也需要展示出来
SELECT e.*, d.name
FROM emp e
    LEFT JOIN dept d ON e.dept_id = d.id
WHERE
    e.age > 40;

-- 5、查询所有员工的工资等级
-- 表：emp, salgrade
-- 连接条件：emp.salary >= salgrade.losal && emp.salary <= salgrade.hisal
SELECT e.name, e.salary, s.grade
FROM emp e, salgrade s
WHERE
    e.salary BETWEEN s.losal AND s.hisal;

-- 6、查询 '研发部' 所有员工的信息及工资等级
SELECT e.*, s.grade
FROM emp e, salgrade s, dept d
WHERE (
        e.salary BETWEEN s.losal AND s.hisal
    ) && e.dept_id = d.id && d.name = '研发部';

-- 7、查询 '研发部' 员工的平均工资
SELECT avg(e.salary)
FROM emp e, dept d
WHERE
    e.dept_id = d.id && d.name = '研发部';

-- 8、查询工资比 '灭绝' 高的员工信息
SELECT *
FROM emp
WHERE
    salary > (
        SELECT salary
        FROM emp
        WHERE
            name = '灭绝'
    );

-- 9、查询比平均薪资高的员工信息
SELECT * FROM emp WHERE salary > ( SELECT avg(salary) FROM emp );

-- 10、查询低于本部门平均工资的员工信息
-- 重点理解
SELECT *
FROM emp b
WHERE
    b.salary < (
        SELECT avg(a.salary)
        FROM emp a
        WHERE
            a.dept_id = b.dept_id
    )

-- 11、查询所有的部门信息，并统计部门的员工人数
-- 重点理解
SELECT d.id, d.name, (
        SELECT count(*)
        FROM emp e
        WHERE
            e.dept_id = d.id
    )
FROM dept d;

-- 12、查询所有学生的选课情况，展示出学生名称、学号、课程名称
-- 表：student, course, student_course
-- 连接条件：student.id = student_course.studentid， course.id = student_course.courseid
SELECT s.name, s.no, c.name
FROM
    student s,
    course c,
    student_course sc
WHERE
    s.id = sc.studentid && c.id = sc.courseid;