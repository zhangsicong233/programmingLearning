-- 删除/更新行为
-- no action / restrict  // 父表中更新/删除时，若该记录有外键则不允许删除/更新
-- cascade  // 父表中更新/删除时，若该记录有外键，则同时删除/更新外键在子表中记录
-- set null  // 父表中删除时，若该记录有外键，则设置子表中该外键值为 null
-- set default  // 父表有变更时，子表将外键设置成一个默认的值(innodb 不支持)

-- ALTER TABLE 表名 ADD CONSTRAINT 外键名称 FOREIGN KEY (外键字段名) REFERENCES 主表 (主表列名) ON UPDATE 行为模式 ON DELETE 行为模式;

ALTER TABLE emp
ADD CONSTRAINT fk_emp_dept_id FOREIGN KEY (dept_id) REFERENCES dept (id) ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE emp
ADD CONSTRAINT fk_emp_dept_id FOREIGN KEY (dept_id) REFERENCES dept (id) ON UPDATE SET NULL ON DELETE SET NULL;