-- 创建视图
-- create [or replace] view 视图名称[(列名的列表)] as select 语句

-- 查询
-- 查看创建视图的语句 show create view 视图名称;
-- 查看视图数据 select * from 视图名称 ... ;  // 把视图当表来查询)

-- 修改
-- create [or replace] view 视图名称[(列名的列表)] as select 语句  // 修改时一定要加 [or replace]
-- alter view 视图名称 as select 语句

-- 删除
-- drop view [if exists] 视图名称