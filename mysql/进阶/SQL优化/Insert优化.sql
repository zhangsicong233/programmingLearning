-- insert 优化
-- 1、批量插入
-- 2、手动提交事务
-- 3、主键顺序插入
/*
eg.
主键乱序插入：0 1 9 21 88 2 4 15 89 5 7 3
主键顺序插入：1 2 3 4 5 7 8 9 15 21 88 89
*/

-- 大批量插入数据
-- 如需一次性插入大量数据，此时使用 insert 语句插入性能较低，此时可用 MySQL 数据库提供的 load 指令进行插入
/*
-- 1、客户端连接服务端时，加上参数 --local-infile
mysql --local-infile -u root -p
-- 2、设置全局参数 local_infile 为 1，开启从本地加载文件导入数据的开关
set global local_infile = 1;
-- 3、执行 load 指令将准备好的数据，加载到表结构中
load data local infile '准备好的数据文件' into table 表名 fields terminated by '分隔符' lines terminated by '\n';
*/