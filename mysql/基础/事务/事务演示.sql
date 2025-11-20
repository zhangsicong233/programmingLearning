-- 转账操作 （张三给李四转账 1000）
-- 1、 查询张三账户余额
SELECT * FROM `account` WHERE name = '张三';

-- 2、将张三账户余额 -1000
UPDATE `account` SET money = money - 1000 WHERE name = '张三';

程序发生异常 ...

-- 3、将李四账户余额 +1000
UPDATE `account` SET money = money - 1000 WHERE name = '李四';

-- 恢复数据
UPDATE `account` SET money = 2000 WHERE name = '张三' || name = '李四';

-- 控制事务两种方式
-- 1、手动设置事务提交方式
-- 查看 / 设置事务提交方式
-- select @@autocommit;
-- set @@autocommit = 0;

-- 2、开启事务
-- begin / start transaction;

-- 提交事务
-- commit

-- 回滚事务
-- rollback

-- 方式 1 示例
SELECT @@autocommit;

SET @@autocommit = 0;

SELECT * FROM `account` WHERE name = '张三';

UPDATE `account` SET money = money - 1000 WHERE name = '张三';

程序出现异常 ...

UPDATE `account` SET money = money + 1000 WHERE name = '李四';

-- 提交事务
COMMIT;
-- 回滚事务
ROLLBACK;

-- 方式 2 示例
START TRANSACTION;

SELECT * FROM `account` WHERE name = '张三';

UPDATE `account` SET money = money - 1000 WHERE name = '张三';

程序出现异常 ...

UPDATE `account` SET money = money + 1000 WHERE name = '李四';

-- 提交事务
COMMIT;
-- 回滚事务
ROLLBACK;