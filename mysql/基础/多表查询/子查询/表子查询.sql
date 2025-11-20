-- 表子查询
-- 子查询返回的结果是多行多列
-- 常用操作符 in

-- 1、查询与 '鹿杖客', '宋远桥' 的职位和薪资相同的员工信息
SELECT *
FROM emp
WHERE (job, salary) IN (
        SELECT job, salary
        FROM emp
        WHERE
            name = '鹿杖客' || name = '宋远桥'
    );

-- 2、查询入职日期是 '2006-01-01' 之后的员工信息及其部门信息
SELECT * FROM emp WHERE entrydate > '2006-01-01';

SELECT a.*, d.*
FROM (
        SELECT *
        FROM emp
        WHERE
            entrydate > '2006-01-01'
    ) a
    LEFT JOIN dept d ON a.dept_id = d.id;