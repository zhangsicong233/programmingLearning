-- count 优化

-- InnoDB 引擎执行 count(*) 时，需要把数据一行一行从引擎读出来然后累计计数

-- 优化思路：没有特别好的优化方法，自己计数

-- count 的几种方式
-- count(*)、count(主键)、count(字段)、count(1)