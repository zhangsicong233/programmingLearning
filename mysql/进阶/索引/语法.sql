-- 创建索引
-- create [unique/fulltext] index index_name on table_name (index_col_name, ...);  // index 之前什么也不加表示创建常规索引

-- 查看索引
-- show index from table_name;

-- 删除索引
-- drop index index_name on table_name;

SHOW INDEX FROM tb_user\G;

-- 1、name 字段为姓名字段, 该字段值可能会重复，为该字段创建索引
CREATE INDEX idx_user_name ON tb_user (name);

-- 2、phone 手机号字段的值，是非空，且唯一的，为该字段创建唯一索引
CREATE UNIQUE INDEX idx_user_phone ON tb_user (phone);

-- 3、为 profession、age、status 创建联合索引
CREATE INDEX idx_user_pro_age_sta ON tb_user (profession, age, status);

-- 4、为 email 建立合适的索引来提升查询效率
CREATE INDEX idx_user_email ON tb_user (email);

SHOW GLOBAL STATUS LIKE 'Com_______';