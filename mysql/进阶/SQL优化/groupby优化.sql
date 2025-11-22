-- group by 优化

-- 分组操作时，通过索引来提高效率
-- 分组操作时，索引的使用也满足最左前缀法则

SHOW INDEX FROM tb_user;

DROP INDEX idx_user_pro_age_sta ON tb_user;

DROP INDEX idx_email_5 ON tb_user;

DROP INDEX idx_user_age_phone ON tb_user;

DROP INDEX idx_user_age_phone_ad ON tb_user;

EXPLAIN
SELECT profession, count(profession)
FROM tb_user
GROUP BY
    profession;

CREATE INDEX idx_user_pro_age_sta ON tb_user (profession, age, status);

EXPLAIN
SELECT profession, count(*)
FROM tb_user
GROUP BY
    profession;

EXPLAIN SELECT age, count(*) FROM tb_user GROUP BY age;

EXPLAIN
SELECT profession, age, count(*)
FROM tb_user
GROUP BY
    profession,
    age;

EXPLAIN
SELECT age, count(*)
FROM tb_user
WHERE
    profession = '软件工程'
GROUP BY
    age;