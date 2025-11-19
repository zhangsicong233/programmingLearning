-- 流程控制函数

-- if(value, t, f)  // 如果 value 为 true，则返回 t， 否则返回 f
SELECT IF(FALSE, 'ok', 'error');

-- ifnull(value1, value2)  // 如果 value1 不为空， 返回 value1，否则返回 value2
SELECT IFNULL(NULL, 'default');

-- case when [val1] then [res1]  ...  else [default] end  // 如果 val1 为 true， 返回 res1， ...  否则返回 default 默认值
-- case [expr] when [val1] then [res1]  ...  else [default] end  // 如果 expr 值为 val1，返回 res1， ...  否则返回 default 默认值
-- 需求：查询 emp 表的员工姓名和工作地址(北京/上海 -----> 一线城市， 其他 -----> 二线城市)
SELECT
    name,
    `workAddress`,
    CASE workAddress
        WHEN '北京' THEN '一线城市'
        WHEN '上海' THEN '一线城市'
        ELSE '二线城市'
    END
FROM emp;

-- 案例：统计班级各个学员的成绩，展示的规则如下：
-- >= 85, 展示优秀
-- >= 60, 展示及格
-- 否则，展示不及格
CREATE TABLE score (
    id int comment 'ID',
    name VARCHAR(20) comment '姓名',
    math int comment '数学',
    english int comment '英语',
    chinese int comment '语文'
) comment '学员成绩表';

INSERT INTO
    score (
        id,
        name,
        math,
        english,
        chinese
    )
VALUES (1, 'Tom', 67, 88, 95),
    (2, 'Rose', 23, 66, 90),
    (3, 'Jack', 56, 98, 76);

SELECT name, (
        CASE
            WHEN math >= 85 THEN '优秀'
            WHEN math >= 60 THEN '及格'
            ELSE '不及格'
        END
    ) AS '数学', (
        CASE
            WHEN english >= 85 THEN '优秀'
            WHEN english >= 60 THEN '及格'
            ELSE '不及格'
        END
    ) AS '英语', (
        CASE
            WHEN chinese >= 85 THEN '优秀'
            WHEN chinese >= 60 THEN '及格'
            ELSE '不及格'
        END
    ) AS '语文'
FROM score;