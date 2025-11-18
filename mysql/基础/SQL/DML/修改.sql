-- 对表修改数据 (UPDATE)

-- employee 表
-- 修改 id 为 1 的数据，将 name 改为 itheima
UPDATE employee SET name = 'itheima' WHERE id = 1;

-- 修改 id 为 1 的数据， 将 name 改为 ‘小昭’， gender 修改为 ‘女’
UPDATE employee SET name = '小昭', gender = '女' WHERE id = 1;

-- 将所有员工入职日期修改为 2008-01-01
UPDATE employee SET `entryDate` = '2008-01-01';