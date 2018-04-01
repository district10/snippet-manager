# network
ifconfig
ip addr

$ cat /etc/issue
$ service networking restart
$ tail -f /var/log/upstart/networking.log

# restart: down, then up
ifdown eth0
ifup eth0

# restart all, except lo
ifdown --exclude=lo -a && sudo ifup --exclude=lo -a
