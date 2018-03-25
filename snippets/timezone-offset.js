// "+08:00", timezone offset
function timezoneOffset() {
    var tzo = -new Date().getTimezoneOffset();
    var dif = tzo >= 0 ? '+' : '-';
    function pad(num) {
        var norm = Math.floor(Math.abs(num));
        return (norm < 10 ? '0' : '') + norm;
    };
    return dif + pad(tzo / 60) + ':' + pad(tzo % 60);
};
