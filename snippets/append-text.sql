use as_order;
UPDATE table1 SET col1 = CONCAT(COALESCE(`col1`,''), 'appended text');
