-- 行子查询
-- 子查询返回的结果是一行（可以是多列）
-- 常用操作符: =, !=(<>), in, not in

-- 1、查询与 '张无忌' 的薪资及直属领导相同的员工信息
SELECT *
FROM emp
WHERE (salary, managerid) = (
        SELECT salary, managerid
        FROM emp
        WHERE
            name = '张无忌'
    );