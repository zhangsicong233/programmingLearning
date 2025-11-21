-- profile 详情
-- 通过 have_profiling 参数，能看到当前 MySQL 是否支持 profile 操作
SELECT @@have_profiling;

-- 默认 profiling 是关闭的，可以通过 set 语句在 session/global 级别开启 profiling
SELECT @@profiling;

SET profiling = 1;

SELECT * FROM tb_user;

SELECT * FROM tb_user WHERE id = 1;

SELECT * FROM tb_user WHERE name = '白起';

SELECT count(*) FROM tb_user;

-- 查看每一条 SQL 的耗时基本情况
-- SHOW PROFILES;
SHOW PROFILES;

-- 查看指定 query_id 的 SQL 语句各个阶段的耗时情况
-- SHOW PROFILE FOR QUERY query_id;
SHOW PROFILE FOR QUERY 4;

SHOW PROFILE CPU FOR QUERY 4;