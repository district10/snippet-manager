# date time, datetime, timestamp
import datetime
print '[' + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) + ']'              # timestamp
ts = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d--%H-%M-%S')    # timestamp
