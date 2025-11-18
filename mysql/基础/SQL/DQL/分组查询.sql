-- 分组查询 (GROUP BY)

-- 1. 根据性别分组，统计男性员工 和 女性员工的数量
SELECT gender, count(gender) FROM emp GROUP BY gender;

-- 2. 根据性别分组，统计男性员工 和 女性员工的平均年龄
SELECT gender, avg(age) FROM emp GROUP BY gender;

-- 3. 查询年龄小于 45 的员工，并根据工作地址分组，获取员工数量大于等于 3 的工作地址
SELECT workAddress, count(`workAddress`)
FROM emp
WHERE
    age < 45
GROUP BY
    `workAddress`
HAVING
    count(`workAddress`) >= 3;