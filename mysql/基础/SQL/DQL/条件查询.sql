-- 条件查询
-- 1. 查询年龄等于 88 的员工
SELECT * FROM emp WHERE age = 88;

-- 2. 查询年龄小于 20 的员工信息
SELECT * FROM emp WHERE age < 20;

-- 3. 查询年龄小于等于 20 的员工信息
SELECT * FROM emp WHERE age <= 20;

-- 4. 查询没有身份证号的员工信息
SELECT * FROM emp WHERE `idCard` IS NULL;

-- 5. 查询有身份证号的员工信息
SELECT * FROM emp WHERE `idCard` IS NOT NULL;

-- 6. 查询年龄不等于 88 的员工信息
SELECT * FROM emp WHERE age != 88;

SELECT * FROM emp WHERE age <> 88;

-- 7. 查询年龄在 15 (包含)到 20 (包含)之间的员工信息
SELECT * FROM emp WHERE age >= 15 && age <= 20;

SELECT * FROM emp WHERE age BETWEEN 15 AND 20;

-- 8. 查询性别为 女 且年龄小于 25 岁的员工信息
SELECT * FROM emp WHERE gender = '女' && age < 25;

-- 9. 查询年龄等于 18 或 20 或 40 的员工信息
SELECT * FROM emp WHERE age = 18 || age = 20 || age = 40;

SELECT * FROM emp WHERE age IN (18, 20, 40);

-- 10. 查询姓名为两个字的员工信息
SELECT * FROM emp WHERE name LIKE '__';

-- 11. 查询身份证号最后一位是 X 的员工信息
SELECT * FROM emp WHERE `idCard` LIKE '%X';