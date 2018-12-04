# date time, datetime, timestamp
import datetime
print '[' + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) + ']'              # timestamp
ts = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d--%H-%M-%S')    # timestamp

# epoch time, unix time
ts = f'{datetime.fromtimestamp(epoch/1000.0).strftime("%Y/%m/%d %H:%M:%S")[:19]}.{epoch%1000:03d}'
