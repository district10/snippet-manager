mongo url:27017/database-name
show dbs
show tables

db.migration_result.remove({fileName: "20180313"})
db.migration_result.find({fileName: "20180203"}).sort({date: -1}).pretty()
