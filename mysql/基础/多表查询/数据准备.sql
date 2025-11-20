CREATE TABLE dept (
    id int PRIMARY KEY auto_increment,
    name varchar(10)
);

INSERT INTO
    dept
VALUES (NULL, '研发部'),
    (NULL, '市场部'),
    (NULL, '财务部'),
    (NULL, '销售部'),
    (NULL, '总经办'),
    (NULL, '人事部');

CREATE TABLE emp (
    id int PRIMARY KEY auto_increment,
    name varchar(10),
    age int,
    job varchar(10),
    salary int,
    entrydate DATE,
    managerid int,
    dept_id int,
    CONSTRAINT fk_dept FOREIGN KEY (dept_id) REFERENCES dept (id)
);

INSERT INTO
    emp
VALUES (
        NULL,
        '金庸',
        66,
        '总裁',
        20000,
        '2000-01-01',
        NULL,
        5
    ),
    (
        NULL,
        '张无忌',
        20,
        '项目经理',
        12500,
        '2005-12-05',
        1,
        1
    ),
    (
        NULL,
        '杨逍',
        33,
        '开发',
        8400,
        '2000-11-03',
        2,
        1
    ),
    (
        NULL,
        '韦一笑',
        48,
        '开发',
        11000,
        '2002-02-05',
        2,
        1
    ),
    (
        NULL,
        '常遇春',
        43,
        '开发',
        10500,
        '2004-09-07',
        3,
        1
    ),
    (
        NULL,
        '小昭',
        19,
        '程序员鼓励师',
        6600,
        '2004-10-12',
        2,
        1
    ),
    (
        NULL,
        '灭绝',
        60,
        '财务总监',
        8500,
        '2002-09-12',
        1,
        3
    ),
    (
        NULL,
        '周芷若',
        19,
        '会计',
        4800,
        '2006-06-02',
        7,
        3
    ),
    (
        NULL,
        '丁敏君',
        23,
        '出纳',
        5250,
        '2009-05-13',
        7,
        3
    ),
    (
        NULL,
        '赵敏',
        20,
        '市场部总监',
        12500,
        '2004-10-12',
        1,
        2
    ),
    (
        NULL,
        '鹿杖客',
        56,
        '职员',
        3750,
        '2006-10-03',
        10,
        2
    ),
    (
        NULL,
        '鹤笔翁',
        19,
        '职员',
        3750,
        '2007-05-09',
        10,
        2
    ),
    (
        NULL,
        '方东白',
        19,
        '职员',
        5500,
        '2009-02-12',
        10,
        2
    ),
    (
        NULL,
        '张三丰',
        88,
        '销售总监',
        14000,
        '2004-10-12',
        1,
        4
    ),
    (
        NULL,
        '俞莲舟',
        38,
        '销售',
        4600,
        '2004-10-12',
        14,
        4
    ),
    (
        NULL,
        '宋远桥',
        40,
        '销售',
        4600,
        '2004-10-12',
        14,
        4
    ),
    (
        NULL,
        '陈友谅',
        42,
        NULL,
        2000,
        '2011-10-12',
        1,
        NULL
    );

CREATE TABLE salgrade ( grade int, losal int, hisal int );

INSERT INTO
    salgrade
VALUES (1, 0, 3000),
    (2, 3001, 5000),
    (3, 5001, 8000),
    (4, 8001, 10000),
    (5, 10001, 15000),
    (6, 15001, 20000),
    (7, 20001, 25000),
    (8, 25001, 30000);