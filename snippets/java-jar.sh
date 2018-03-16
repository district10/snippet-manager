java -Xmx1g -Xms256m -XX:+UseAdaptiveSizePolicy \
    -XX:+UseSerialGC -XX:+PrintGCDetails -XX:+PrintGCTimeStamps \
    -XX:+PrintGCDateStamps -XX:+PrintHeapAtGC -verbose:gc -XX:+PrintTenuringDistribution \
    -XX:+PrintGCApplicationStoppedTime -Xloggc:gc_as_order.log -jar app.jar
