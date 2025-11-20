CREATE TABLE account (
    id INT AUTO_INCREMENT PRIMARY KEY COMMENT '主键ID',
    name VARCHAR(10) COMMENT '姓名',
    money INT COMMENT '余额'
) COMMENT '账户表';

INSERT INTO
    account (id, name, money)
VALUES (NULL, '张三', 2000),
    (NULL, '李四', 2000);