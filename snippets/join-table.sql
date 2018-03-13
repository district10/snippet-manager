USE as_vehicle;
SELECT DISTINCT xxx
FROM table_xxx
  INNER JOIN table_yyy
    ON (table_xxx.id = table_yyy.prod_id)
WHERE some_id = 'XY'
      AND table_xxx.opq LIKE '闽AW'
      AND table_yyy.uvw IS NOT NULL;
LIMIT 1;
