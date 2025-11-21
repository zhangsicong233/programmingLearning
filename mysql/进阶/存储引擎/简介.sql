-- 查询建表语句
SHOW CREATE TABLE account;

-- 查看当前数据库支持的存储引擎
SHOW ENGINES;

-- 案例
-- 创建表 my_myisam, 并指定 MyISAM 存储引擎
CREATE TABLE my_myisam (id int, name VARCHAR(10)) engine = MyISAM;

-- 创建表 my_memory, 指定 Memory 存储引擎
CREATE TABLE my_memory (id int, name VARCHAR(10)) engine = Memory;