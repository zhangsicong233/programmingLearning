-- 数值函数

-- ceil/floor (x)  // 向上/下取整
SELECT CEIL(5.5);

SELECT FLOOR(1.5);

-- mod (x, y)  // 返回 x/y 的模(取余)
SELECT MOD(6, 4);

-- rand ()  // 返回 0-1 内的随机数
SELECT rand();

-- round (x, y)  // 求 x 的四舍五入的值，保留 y 位小数
SELECT ROUND(2.344, 2);

-- 案例
-- 通过数据库的函数，生成一个六位数的随机验证码
SELECT LPAD( FLOOR(rand() * 1e6), 6, FLOOR(rand() * 1e6) );