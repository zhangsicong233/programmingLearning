-- 检查选项 with check option
-- 两个选项 cascaded 和 local  // 默认为 cascaded
-- cascaded 递归检查
CREATE VIEW stu_v_1 AS
SELECT id, name
FROM student
WHERE
    id <= 20;

INSERT INTO stu_v_1 VALUES (5, 'Tom');

INSERT INTO stu_v_1 VALUES (25, 'Tom');

CREATE VIEW stu_v_2 AS
SELECT id, name
FROM stu_v_1
WHERE
    id >= 10
WITH
    CASCADED CHECK OPTION;

INSERT INTO stu_v_2 VALUES (7, 'Tom');

INSERT INTO stu_v_2 VALUES (26, 'Tom');

INSERT INTO stu_v_2 VALUES (15, 'Tom');

CREATE VIEW stu_v_3 AS
SELECT id, name
FROM stu_v_2
WHERE
    id <= 15;

INSERT INTO stu_v_3 VALUES (11, 'Tom');

INSERT INTO stu_v_3 VALUES (17, 'Tom');

INSERT INTO stu_v_3 VALUES (28, 'Tom');