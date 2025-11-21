-- 前缀索引
-- 当字段类型是字符串（varchar，text等）可以只将字符串的一部分前缀建立索引
-- create index idx_xxxx on table_name(column(n));

-- 前缀长度
-- 根据索引选择性决定
-- 选择性指不重复的索引值和记录表记录总数的比值（越高越好）
-- select count(distinct email) / count(*) from tb_user;
-- select count(distinct substring(email, 1, 5)) / count(*) from tb_user;

SELECT count(*) FROM tb_user;

SELECT count(DISTINCT email) FROM tb_user;

-- email 选择性
SELECT COUNT(DISTINCT email) / COUNT(*) FROM tb_user;

SELECT count(
        DISTINCT SUBSTRING(email, 1, 4)
    ) / count(*)
FROM tb_user;

SHOW INDEX FROM tb_user;

CREATE INDEX idx_email_5 ON tb_user (email (5));

EXPLAIN SELECT * FROM tb_user WHERE email = 'daqiao666@sina.com';