-- 更新
-- 必须与基础表中的行一一对应
-- 有以下任何一项，不可更新
-- 1、聚合函数/窗口函数
-- 2、distinct
-- 3、group by
-- 4、having
-- 5、union 或 union all

CREATE VIEW stu_v_count AS SELECT count(*) FROM student;

INSERT INTO stu_v_count VALUES (10);