curl -X GET https://requestb.in/s437tns4

curl -X POST -H 'key: value' https://requestb.in/s437tns4 -d '{ "ping": "pong" }'  # --data

curl --data "birthyear=1905&press=%20OK%20"  http://www.example.com/junk.cgi # form data
// <form method="POST" action="junk.cgi">
//     <input type=text name="birthyear">
//     <input type=submit name=press value=" OK ">
// </form>

curl -X POST https://requestb.in/yx5thyyx \
  -H 'content-type: multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW' \
  -F filekey1=@/private/tmp/file1 \
  -F filekey2=@/private/tmp/file2.json

// -v           # --verbose
// -vv          # Even more verbose
// -u user:pass # --user: Authentication
