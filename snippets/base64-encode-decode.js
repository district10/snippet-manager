function base64Encode( str ) {
    return window.btoa(unescape(encodeURIComponent( str )));
}

function base64Decode( str ) {
    return decodeURIComponent(escape(window.atob( str )));
}

// 使用方法
base64Encode('你好') // "5L2g5aW9"
base64Decode('5L2g5aW9') // "你好"

$ echo '你好' | base64
5L2g5aW9Cg==
$ echo -n '你好' | base64
5L2g5aW9
