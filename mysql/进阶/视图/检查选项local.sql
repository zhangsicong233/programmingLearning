-- local
CREATE VIEW stu_v_4 AS
SELECT id, name
FROM student
WHERE
    id <= 20;

INSERT INTO stu_v_4 VALUES (5, 'Tom');

INSERT INTO stu_v_4 VALUES (16, 'Tom');

CREATE VIEW stu_v_5 AS
SELECT id, name
FROM stu_v_4
WHERE
    id >= 10
WITH
    CASCADED CHECK OPTION;

INSERT INTO stu_v_5 VALUES (13, 'Tom');

INSERT INTO stu_v_5 VALUES (17, 'Tom');

CREATE VIEW stu_v_6 AS
SELECT id, name
FROM stu_v_5
WHERE
    id <= 25
WITH
    LOCAL CHECK OPTION;

INSERT INTO stu_v_6 VALUES (21, 'Tom');