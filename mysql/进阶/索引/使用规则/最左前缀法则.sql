-- 最左前缀法则
-- 如果索引了多列（联合索引）, 要遵守最左前缀法则。
-- 最左前缀法则指 查询从索引的最左列开始，且不跳过索引中的列
-- 如果跳过某一列，索引将部分失效（后面的字段索引失效）

SELECT * FROM tb_user;

SHOW INDEX FROM tb_user;

EXPLAIN
SELECT *
FROM tb_user
WHERE
    profession = '软件工程' && age = 31 && status = '0';

EXPLAIN SELECT * FROM tb_user WHERE profession = '软件工程' && age = 31;

EXPLAIN SELECT * FROM tb_user WHERE profession = '软件工程';

EXPLAIN SELECT * FROM tb_user WHERE age = 31 && status = '0';

EXPLAIN SELECT * FROM tb_user WHERE status = '0';

EXPLAIN
SELECT *
FROM tb_user
WHERE
    profession = '软件工程' && status = '0';

-- 范围查询
-- 联合索引中，出现范围查询 （ >, <), 范围查询右侧的列索引失效
EXPLAIN
SELECT *
FROM tb_user
WHERE
    profession = '软件工程' && age > 30 && status = '0';