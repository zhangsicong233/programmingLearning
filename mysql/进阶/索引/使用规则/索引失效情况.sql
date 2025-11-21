-- 1、索引列运算
-- 不要在索引列上进行运算操作，索引将失效
EXPLAIN SELECT * FROM tb_user WHERE phone = '17799990015';

EXPLAIN SELECT * FROM tb_user WHERE SUBSTRING(phone, 10, 2) = '15';

-- 2、字符串不加单引号
EXPLAIN SELECT * FROM tb_user WHERE phone = 17799990015;

EXPLAIN
SELECT *
FROM tb_user
WHERE
    profession = '软件工程' && age = 31 && status = 0;

-- 3、模糊查询 (like)
-- 仅仅是尾部模糊匹配，索引不会失效；头部模糊匹配，索引会失效
-- 会走索引
EXPLAIN SELECT * FROM tb_user WHERE profession LIKE '软件%';

-- 不会走索引
EXPLAIN SELECT * FROM tb_user WHERE profession LIKE '%工程';

-- 4、or 连接的条件
-- 用 or 分隔开的条件，如果 or 前的条件中的列有索引，后面的列中没有索引，那么涉及的索引都不会被用到
EXPLAIN SELECT * FROM tb_user WHERE id = 10 || age = 23;

EXPLAIN
SELECT *
FROM tb_user
WHERE
    phone = '17799990017' || age = 23;

CREATE INDEX idx_user_age ON tb_user (age);

-- 5、数据分布影响
-- 如果 MySQL 评估使用索引比全表扫描慢，则不用索引
SELECT * FROM tb_user;

EXPLAIN SELECT * FROM tb_user WHERE phone >= '17799990013';

EXPLAIN SELECT * FROM tb_user WHERE profession IS NULL;

EXPLAIN SELECT * FROM tb_user WHERE profession IS NOT NULL;