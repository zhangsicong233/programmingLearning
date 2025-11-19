-- 外键约束

-- 数据准备
CREATE TABLE dept (
    id int auto_increment comment 'ID' KEY,
    name varchar(50) NOT NULL comment '部门名称'
) comment '部门表';

INSERT INTO
    dept (id, name)
VALUES (1, '研发部'),
    (2, '市场部'),
    (3, '财务部'),
    (4, '销售部'),
    (5, '总经办');

CREATE TABLE emp (
    id int auto_increment comment 'ID' KEY,
    name varchar(50) NOT NULL comment '姓名',
    age int comment '年龄',
    job varchar(20) comment '职位',
    salary int comment '薪资',
    entrydate DATE comment '入职时间',
    managerid int comment '直质领导ID',
    dept_id int comment '部门ID'
) comment '员工表1';

INSERT INTO
    emp (
        id,
        name,
        age,
        job,
        salary,
        entrydate,
        managerid,
        dept_id
    )
VALUES (
        1,
        '金庸',
        66,
        '总裁',
        20000,
        '2000-01-01',
        NULL,
        5
    ),
    (
        2,
        '张无忌',
        20,
        '项目经理',
        12500,
        '2005-12-05',
        1,
        1
    ),
    (
        3,
        '杨逍',
        33,
        '开发',
        8400,
        '2000-11-03',
        2,
        1
    ),
    (
        4,
        '书一笑',
        48,
        '开发',
        11000,
        '2002-02-05',
        2,
        1
    ),
    (
        5,
        '常遇春',
        43,
        '开发',
        10500,
        '2004-09-07',
        3,
        1
    ),
    (
        6,
        '小昭',
        19,
        '程序员鼓励师',
        6600,
        '2004-10-12',
        2,
        1
    );

-- 建立外键关联
-- ALTER TABLE 表名 ADD CONSTRAINT 外键名称 FOREIGN KEY (外键字段名) REFERENCES 主表 (主表列名);
ALTER TABLE emp
ADD CONSTRAINT fk_emp_dept_id FOREIGN KEY (dept_id) REFERENCES dept (id);

-- 删除外键
-- ALTER TABLE 表名 DROP FOREIGN KEY 外键名称
ALTER TABLE emp DROP FOREIGN KEY fk_emp_dept_id;