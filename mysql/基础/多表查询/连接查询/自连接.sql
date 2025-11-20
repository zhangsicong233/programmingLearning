-- 自连接
-- SELECT 字段 FROM 表A 别名A (INNER/LEFT) JOIN 表A 别名B ON 条件
-- 注：自连接查询，可以是内连接查询也可以是外连接查询

-- 1、查询员工及其所属领导的名字
SELECT a.name '员工', b.name '领导'
FROM emp a
    INNER JOIN emp b ON a.managerid = b.id;

-- 2、查询所有员工 emp 及其领导的名字 emp，如果员工没有领导也要查询出来
SELECT a.name '员工', b.name '领导'
FROM emp a
    LEFT JOIN emp b ON a.managerid = b.id;