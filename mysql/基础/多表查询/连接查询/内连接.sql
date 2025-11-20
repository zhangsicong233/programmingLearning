-- 内连接

-- 查询的两表交集部分数据
-- 隐式内连接
-- SELECT 字段 FROM 表1，表2 WHERE 条件 ... ;

-- 显式内连接
-- SELECT 字段 FROM 表1 [INNER] JOIN 表2 ON 连接条件 ... ;

-- 1、查询每一个员工的姓名，及关联部门的名称
SELECT emp.name, dept.name
FROM emp, dept
WHERE
    emp.dept_id = dept.id;

SELECT e.name, d.name
FROM emp e
    INNER JOIN dept d ON e.dept_id = d.id;