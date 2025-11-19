-- 日期函数

-- curdate()  // 返回当前日期
SELECT CURDATE();

-- curtime()  // 返回当前时间
SELECT CURTIME();

-- now()  // 返回当前日期和时间
SELECT NOW();

-- year/month/day (date)  // 获取指定 date 的年份/月份/日期
SELECT YEAR(CURDATE());

SELECT MONTH(CURDATE());

SELECT DAY(CURDATE());

-- date_add(date, interval expr type)  // 返回上一个日期/时间值加上一个时间间隔 expr 后的时间值
SELECT DATE_ADD(CURDATE(), INTERVAL 100 YEAR);

-- datediff(date1, date2)  // 返回起始时间 date1 和结束时间 date2 之间的天数
SELECT DATEDIFF(CURDATE(), '2026-06-01');

-- 案例
-- 查询所有员工的入职天数，并根据入职天数倒叙排序
SELECT name, DATEDIFF(CURDATE(), emp.`entryDate`) AS '入职天数'
FROM emp
ORDER BY 入职天数 DESC;