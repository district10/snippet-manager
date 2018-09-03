document.getElementsByTagName("body")[0].onkeypress = evt => {
    evt = evt || window.event;
    var charCode = evt.keyCode || evt.which;
    if (false) {
    } else if (charCode == 13) { // "<enter>"
    } else if (charCode == 32) { // "<space>"
    }
};
