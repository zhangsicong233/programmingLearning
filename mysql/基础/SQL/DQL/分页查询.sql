-- 分页查询 (LIMIT)

-- 1. 查询第 1 页员工数据，每页展示 10 条记录
SELECT * FROM emp LIMIT 10;

-- 2. 查询第 2 页员工数据，每页展示 10 条记录
SELECT * FROM emp LIMIT 10, 10;