var detected;

export function utilDetect(force) {
    if (detected && !force) return detected;
    detected = {};

    var ua = navigator.userAgent,
        m = null;

    m = ua.match(/(edge)\/?\s*(\.?\d+(\.\d+)*)/i);   // Edge
    if (m !== null) {
        detected.browser = m[1];
        detected.version = m[2];
    }
    if (!detected.browser) {
        m = ua.match(/Trident\/.*rv:([0-9]{1,}[\.0-9]{0,})/i);   // IE11
        if (m !== null) {
            detected.browser = 'msie';
            detected.version = m[1];
        }
    }
    ...
    return detected;
}
