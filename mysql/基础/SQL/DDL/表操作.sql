-- 展示所有表
-- show TABLES;
SHOW TABLES;

-- 创建表 (CREATE)
-- CREATE TABLE 表名 （字段1 字段类型, 字段2 字段类型 ... 字段n 字段类型);
CREATE TABLE emp (
    id INT COMMENT '编号',
    workNo VARCHAR(10) COMMENT '工号',
    name VARCHAR(10) COMMENT '姓名',
    gender CHAR(1) COMMENT '性别',
    age TINYINT UNSIGNED COMMENT '年龄',
    idCard CHAR(18) COMMENT '身份证号',
    entryDate DATE COMMENT '入职时间'
) COMMENT '员工表';

-- 查询表
-- 简单查询
-- DESC 表名
DESC emp;

-- 完整查询
-- SHOW CREATE TABLE 表名;
SHOW CREATE TABLE emp;

-- 修改表 (ALTER)
-- ALTER TABLE 表名 ADD/MODIFY/CHANGE/DROP/RENAME TO ...

-- 增加
ALTER TABLE emp ADD nickname VARCHAR(20) COMMENT '昵称';

-- 修改
ALTER TABLE emp MODIFY nickname VARCHAR(100);

ALTER TABLE emp CHANGE nickname username varchar(30);

-- 删除
ALTER TABLE emp DROP username;

-- 修改表名
ALTER TABLE emp RENAME TO employee;

-- 删除表 (DROP)
-- DROP 表名;
DROP TABLE IF EXISTS employee;