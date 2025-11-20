-- 列子查询
-- 子查询返回的是一列（可以是多行）
-- 常用操作符：in, not in, any, some, all

-- 1、查询 '销售部' 和 '市场部' 的所有成员信息
SELECT *
FROM emp
WHERE
    dept_id IN (
        SELECT id
        FROM dept
        WHERE
            name = '销售部' || name = '市场部'
    );

-- 2、查询比财务部所有人工资都高的员工信息
SELECT *
FROM emp
WHERE
    salary > ALL (
        SELECT salary
        FROM emp
        WHERE
            dept_id = (
                SELECT id
                FROM dept
                WHERE
                    name = '财务部'
            )
    );

-- 3、查询比研发部其中任意一人工资高的员工信息
SELECT *
FROM emp
WHERE
    salary > ANY (
        SELECT salary
        FROM emp
        WHERE
            dept_id = (
                SELECT id
                FROM dept
                WHERE
                    name = '研发部'
            )
    );