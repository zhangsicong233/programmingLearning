-- SQL 提示
-- 在 SQL 语句中加入一些人为的提示来达到优化操作的目的
-- 1、use index;
-- 2、ignore index;
-- 3、force index;
SHOW INDEX FROM tb_user;

CREATE INDEX idx_user_pro ON tb_user (profession);

EXPLAIN SELECT * FROM tb_user WHERE profession = '软件工程';

EXPLAIN
SELECT *
FROM tb_user
USE INDEX (idx_user_pro)
WHERE
    profession = '软件工程';

EXPLAIN
SELECT *
FROM tb_user IGNORE INDEX (idx_user_pro)
WHERE
    profession = '软件工程';

EXPLAIN
SELECT *
FROM tb_user FORCE INDEX (idx_user_pro)
WHERE
    profession = '软件工程';