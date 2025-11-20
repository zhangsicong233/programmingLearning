-- 外连接

-- 左外连接
-- SELECT 字段 FROM 表1 LEFT [OUTER] JOIN 表2 ON 条件 ... ;

-- 右外连接
-- SELECT 字段 FROM 表1 RIGHT [OUTER] JOIN 表2 ON 条件 ... ;

-- 查询 emp 表的所有数据，和对应的部门信息
SELECT e.*, d.name FROM emp e LEFT JOIN dept d ON e.dept_id = d.id;

-- 查询 dept 表的所有数据，和对应员工信息
SELECT d.*, e.* FROM emp e RIGHT JOIN dept d ON e.dept_id = d.id;