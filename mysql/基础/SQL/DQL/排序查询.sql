-- 排序查询 (ORDER BY)(DESC 降序)

-- 1. 根据年龄对公司员工进行升序排序
SELECT * FROM emp ORDER BY age;

-- 2. 根据入职时间，对员工进行降序排序
SELECT * FROM emp ORDER BY `entryDate` DESC;

-- 3. 根据年龄对公司的员工进行升序排序，年龄相同，再按照入职时间进行降序排序
SELECT * FROM emp ORDER BY age, `entryDate` DESC;