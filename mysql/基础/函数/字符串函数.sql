-- 字符串函数

-- concat(str1, str2)  // 字符串拼接
SELECT CONCAT('hello', 'mysql');

-- lower / upper (str)  // 全小写/大写
SELECT LOWER('Hello');

SELECT UPPER('Hello');

-- lpad / rpad (str1, n, str2)  // 左/右填充 将 str1 从左/右用 str2 填充到长度 n
SELECT LPAD('01', 5, '-1');

SELECT RPAD('01', 5, '1-');

-- trim (str)  // 将 str 去除头部和尾部两边空格(不会去掉中间的空格)
SELECT TRIM(' Hello world ');

-- substring (str, start, len)  // 将 str 从 strat 位置开始(索引值从 1 开始)，截取 len 长度的字符串
SELECT SUBSTRING('hello world', 1, 5);

-- 案例
-- 由于业务需求变更，企业员工的工号，统一为五位数，目前不足五位数的全部在前面补 0。比如：1 号员工的工号应该为 00001
UPDATE emp SET `workNo` = LPAD(`workNo`, 5, '0');