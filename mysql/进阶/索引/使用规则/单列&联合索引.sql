-- 单列索引&联合索引
EXPLAIN
SELECT id, phone, name
FROM tb_user
WHERE
    phone = '17799990010' && name = '韩信';

CREATE UNIQUE INDEX idx_user_phone_name ON tb_user (phone, name);

SHOW INDEX FROM tb_user;

EXPLAIN
SELECT id, phone, name
FROM tb_user
USE INDEX (idx_user_phone_name)
WHERE
    phone = '17799990010' && name = '韩信';