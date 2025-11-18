-- 1. 查询年龄为 20, 21, 22, 23 岁的员工信息
SELECT * FROM emp WHERE age IN (20, 21, 22, 23);

-- 2. 查询性别为 男，并且年龄再 20 - 40 岁（含）的姓名为三个字的员工
SELECT *
FROM emp
WHERE
    gender = '男' && age BETWEEN 20 AND 40  && name LIKE '___';

-- 3. 统计员工表中，年龄小于 60 岁的，男性员工和女性员工的人数
SELECT gender, count(gender) FROM emp WHERE age < 60 GROUP BY gender;

-- 4. 查询所有年龄小于等于 35 岁员工的姓名和年龄，并对查询结果按年龄升序排序，弱国年龄相同按入职时间降序排序
SELECT name, age
FROM emp
WHERE
    age <= 35
ORDER BY age, `entryDate` DESC;

-- 5. 查询性别为男，且年龄在 20 - 40 岁（含）的前 5 个员工信息，对查询的结果按年龄升序排序，年龄相同按入职时间升序排序
SELECT *
FROM emp
WHERE
    gender = '男' && age BETWEEN 20 AND 40
ORDER BY age, `entryDate`
LIMIT 5;