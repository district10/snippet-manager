CREATE DATABASE db_name
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'en_US.utf8'
    LC_CTYPE = 'en_US.utf8'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;
-- DROP DATABASE db_name;

CREATE EXTENSION postgis;

drop table if exists db_table;
create table db_table
(
    uuid varchar(36) primary key,
    info text not null,
    center geometry(pointz,4326) not null,
    area double precision
);

"insert into db_table (uuid, info, area, center) values ('{}', '{}', '{}', '{}', st_geomfromtext('pointz ({} {} {})',4326))".format(uuid, info, area, x, y, z)
select uuid, st_x(center), st_y(center), st_z(center) from db_table
