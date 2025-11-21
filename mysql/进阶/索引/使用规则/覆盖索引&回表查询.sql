-- 覆盖索引
-- 查询使用了索引，并且需要返回的列，在该索引中已经全部能找到
-- 尽量使用覆盖索引，减少 select *

-- using index condition
-- 查找使用了索引，但是需要回表查询数据
-- using where；using index
-- 查找使用了索引，但是需要的数据都在索引列中能找到，所以不需要回表

SHOW INDEX FROM tb_user;

DROP INDEX idx_user_age ON tb_user;

DROP INDEX idx_user_email ON tb_user;

DROP INDEX idx_user_pro ON tb_user;

EXPLAIN
SELECT *
FROM tb_user
WHERE
    profession = '软件工程' && age = 31 && status = '0';

EXPLAIN
SELECT id, profession
FROM tb_user
WHERE
    profession = '软件工程' && age = 31 && status = '0';

EXPLAIN
SELECT id, profession, age, status
FROM tb_user
WHERE
    profession = '软件工程' && age = 31 && status = '0';

EXPLAIN
SELECT id, profession, age, status, name
FROM tb_user
WHERE
    profession = '软件工程' && age = 31 && status = '0';