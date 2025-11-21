-- explain 执行计划

-- explain / desc 命令获取 MySQL 如何执行 select 语句的信息，包括在 select 语句执行过程中表如何连接和连接的顺序
-- 直接在 select 语句前加上关键字 explain / desc
-- explain select 字段列表 from 表名 where 条件
EXPLAIN SELECT * FROM tb_user WHERE id = 1;

-- explain 执行计划各字段含义：
-- id
-- select 查询的序列号，表示查询中执行 select 子句或者操作表的顺序（id 相同， 执行顺序从上到下；id 不同，值越大，越先执行）
-- select_type
-- 表示 select 的类型
-- type
-- 表示连接类型，性能由好到差的连接类型为 null、system、const、eq_ref、ref、range、index、all。
-- possible_key
-- 表示可能应用在这张表上的索引，一个或多个
-- key
-- 表示实际用到的索引，如果为 null，表示没有用到索引
-- key_len
-- 表示索引中使用的字节数，该值为索引字段最大可能长度，并非实际使用长度，在不损失精确性前提下，长度越短越好
-- rows
-- 表示 MySQL 任务必须要执行查询的行数，在 innodb 引擎表中，是一个估计值
-- filtered
-- 表示返回结果的行数占所读取行数的百分比，越大越好
-- extra
-- 查询过程中, 前面所有字段没展示出来的值会展示在 extra 中
SELECT s.*, c.*
FROM
    student s,
    course c,
    student_course sc
WHERE
    s.id = sc.studentid && c.id = sc.courseid;

EXPLAIN
SELECT s.name
FROM student s
WHERE
    s.id IN (
        SELECT sc.studentid
        FROM student_course sc
        WHERE
            sc.courseid = (
                SELECT id
                FROM course c
                WHERE
                    c.name = 'Mysql'
            )
    );

SHOW INDEX FROM tb_user;

EXPLAIN SELECT * FROM tb_user WHERE name = '白起';