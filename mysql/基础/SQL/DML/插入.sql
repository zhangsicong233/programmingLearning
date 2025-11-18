-- 对表添加数据 (INSERT)
INSERT INTO
    employee (
        id,
        `workNo`,
        name,
        gender,
        age,
        `idCard`,
        `entryDate`
    )
VALUES (
        1,
        '1',
        'xunfang233',
        '男',
        10,
        '123456789012345678',
        '2000-01-01'
    );

INSERT INTO
    employee
VALUES (
        2,
        '2',
        '张无忌',
        '男',
        '18',
        '123456789012345678',
        '2005-01-01'
    );

INSERT INTO
    employee
VALUES (
        3,
        '3',
        '韦一笑',
        '男',
        '23',
        '123456789012345679',
        '2005-10-01'
    ),
    (
        4,
        '4',
        '赵敏',
        '女',
        '18',
        '223456789012345679',
        '2006-01-01'
    )