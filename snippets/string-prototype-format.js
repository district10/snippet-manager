// js string format, interpolate
String.prototype.format = function () {
    var str = this;
    for ( var i = 0; i < arguments.length; i ++ ) {
        str = str.replace( '{' + i + '}', arguments[ i ] );
    }
    return str;
};
