function toJSON(url, callback) {
    $.get(url, function (data) {
        callback(JSON.parse(data));
    }, 'text');
}
