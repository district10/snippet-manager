window.addEventListener("dragenter", e => { e = e || event; e.preventDefault(); }, false);
window.addEventListener("dragover", e => { e = e || event; e.preventDefault(); }, false);
window.addEventListener("drop", e => { e = e || event; e.preventDefault(); dropHandler(e, dosomething); }, false);

function dropHandler(ev, callback) {
    if (ev.dataTransfer.items) {
        for (var i = 0; i < ev.dataTransfer.items.length; i++) {
            if (ev.dataTransfer.items[i].kind === 'file') {
                var file = ev.dataTransfer.items[i].getAsFile();
                callback(file, file.name);
            }
        }
        ev.dataTransfer.items.clear();
    } else {
        for (var i = 0; i < ev.dataTransfer.files.length; i++) {
            var file = ev.dataTransfer.files[i];
            callback(file, file.name);
        }
        ev.dataTransfer.clearData();
    }
};
