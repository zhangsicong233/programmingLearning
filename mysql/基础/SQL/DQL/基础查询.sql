-- 对表查询 （SELECT）

-- 基本查询
-- 1. 查询指定字段 name，workNo，age
SELECT name, workNo, age FROM emp;

-- 2. 查询所有字段
SELECT * FROM emp;

-- 3. 查询所有员工的工作地址，起别名
SELECT workAddress AS '工作地址' FROM emp;

-- 4. 查询公司员工的上班地址（不要重复）
SELECT DISTINCT workAddress FROM emp;