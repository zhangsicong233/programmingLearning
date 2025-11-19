-- 约束

-- not null (非空约束)
-- unique (唯一约束)
-- primary key (主键约束)
-- default (默认约束)
-- check (检查约束)
-- foreign key (外键约束)

-- 创建表
CREATE TABLE user (
    id INT PRIMARY KEY AUTO_INCREMENT COMMENT '主键',
    name VARCHAR(10) UNIQUE NOT NULL COMMENT '姓名',
    age INT CHECK (age > 0 && age <= 120) COMMENT '年龄',
    status CHAR(1) DEFAULT '1' COMMENT '状态',
    gender CHAR(1) COMMENT '性别'
) COMMENT '用户表'

-- 插入数据
INSERT INTO
    user (name, age, status, gender)
VALUES ("Tom1", 19, '1', '男'),
    ("Tom2", 25, '0', '男');

INSERT INTO
    `user` (name, age, status, gender)
VALUES ('Tom3', 19, '1', '男');

-- name 约束验证
INSERT INTO
    `user` (name, age, status, gender)
VALUES (NULL, 19, '1', '男');

INSERT INTO
    `user` (name, age, status, gender)
VALUES ('Tom3', 19, '1', '男');

-- age 约束验证
INSERT INTO
    `user` (name, age, status, gender)
VALUES ('Tom4', 80, '1', '男');

INSERT INTO
    `user` (name, age, status, gender)
VALUES ('Tom5', -1, '1', '男');

INSERT INTO
    `user` (name, age, status, gender)
VALUES ('Tom5', 121, '1', '男');

-- status 约束验证
INSERT INTO `user` (name, age, gender) VALUES ('Tom5', 120, '男');