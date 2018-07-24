python -m SimpleHTTPServer 8888          # python 2
python -m http.server      8888          # python 3+
php -S localhost:8888                    # php
ruby -run -e httpd . -p 8888             # ruby
http-server                              # node.js: [c]npm install http-server -g
java -jar jetty-runner.jar --port 8888 . # java
double click `mongoose-free-5.5.exe`     # windows

ret=`python -c 'import sys; print("%i" % (sys.version_info[0]))'`
if [ $ret -eq 2 ]; then
    python -m SimpleHTTPServer # Python 2
else
    python -m http.server # Python 3
fi
