-- 聚合函数 count，max，min，avg，sum

-- 1. 统计该企业员工数量
SELECT count(id) FROM emp;

-- 2. 统计该企业员工的平均年龄
SELECT avg(age) FROM emp;

-- 3. 统计该企业员工的最大年龄
SELECT max(age) FROM emp;

-- 4. 统计该企业员工的最小年龄
SELECT min(age) FROM emp;

-- 5. 统计西安地区员工的年龄之和
SELECT sum(age) FROM emp WHERE `workAddress` = '西安';