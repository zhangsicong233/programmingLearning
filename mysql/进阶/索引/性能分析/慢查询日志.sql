-- 慢查询日志记录了所有执行时间超过指定参数（long_query_time, 单位：秒, 默认 10 秒）的所有 SQL 语句的日志
-- MySQL 慢查询日志默认未开启，需要在 MySQL 配置文件（/etc/my.cnf）中配置
-- # 开启 MySQL 慢查询日志开关
-- slow_query_log = 1
-- # 设置慢查询日志的时间，SQL 语句执行时间超过所设置时间就会视为慢查询，记录到慢查询日志中
-- long_query_time = 1;

SHOW VARIABLES LIKE 'slow_query_log';

SELECT * FROM tb_user;