-- order by 优化

-- 1、Using filesort：通过表的索引或全表扫描，读取满足条件的数据行，然后再排序缓冲区 sort buffer 中完成排序操作，所有不是通过索引直接返回排序结果的排序都叫 FileSort 排序
-- 2、Using index：通过有序索引顺序扫描直接返回有序数据，这种情况即为 using index，不需要额外排序，操作效率高

-- 根据排序字段建立合适的索引，多字段排序时，也要遵循最左前缀法则
-- 尽量使用覆盖索引
-- 多字段排序，一个升序一个降序，此时需要注意联合索引在创建时的规则（ACS / DESC）
-- 如果不可避免出现 filesort，大数据量排序时，可以适当增大排序缓冲区大小 sort_buffer_size(默认 256k)

SHOW INDEX FROM tb_user;

DROP INDEX idx_user_phone_name ON tb_user;

DROP INDEX idx_user_phone ON tb_user;

DROP INDEX idx_user_name ON tb_user;

EXPLAIN SELECT id, age, phone FROM tb_user ORDER BY age;

EXPLAIN SELECT id, age, phone FROM tb_user ORDER BY age, phone;

CREATE INDEX idx_user_age_phone ON tb_user (age, phone);

EXPLAIN
SELECT id, age, phone
FROM tb_user
ORDER BY age DESC, phone DESC;

EXPLAIN SELECT id, age, phone FROM tb_user ORDER BY phone, age;

EXPLAIN SELECT id, age, phone FROM tb_user ORDER BY age, phone DESC;

CREATE INDEX idx_user_age_phone_ad ON tb_user (age ASC, phone DESC);

EXPLAIN SELECT id, age, phone FROM tb_user ORDER BY age DESC, phone;

EXPLAIN SELECT * FROM tb_user ORDER BY age, phone;