-- 联合查询（union，union all）
/*
select 字段 from 表A ... 
union [all]
select 字段 from 表B ... ;
*/
-- 有 all 表示直接相连
-- 没有 all 表示去重后相连
-- 注：联合查询的多张表列数必须保持一致，字段类型也必须保持一致

-- 将薪资低于 5000 的员工，和年龄大于 50 岁的员工全部查询出来
SELECT *
FROM emp
WHERE
    salary < 5000
UNION ALL
SELECT *
FROM emp
WHERE
    age > 50;

SELECT *
FROM emp
WHERE
    salary < 5000
UNION
SELECT *
FROM emp
WHERE
    age > 50;