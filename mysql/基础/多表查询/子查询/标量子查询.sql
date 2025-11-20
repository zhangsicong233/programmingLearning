-- 标量子查询
-- 子查询返回的结果是单个值
-- 常用操作符 =, <>(!=), >, >=, <, <=

-- 1、查询 '销售部' 的所有员工信息
SELECT *
FROM emp
WHERE
    dept_id = (
        SELECT id
        FROM dept
        WHERE
            name = '销售部'
    );

-- 2、查询在 '方东白' 入职之后的员工信息
SELECT *
FROM emp
WHERE
    entrydate > (
        SELECT entrydate
        FROM emp
        WHERE
            name = '方东白'
    );