this.fileInput = $('<input type="file" />');
this.fileInput.on("change", function(e){
    var f = e.target.files[0];
    if (f) {
        var r = new FileReader();
        r.onload = function(event) {
            // TODO( event.target.result );
        };
        r.readAsDataURL(f);
    }
});
this.loadTexture = function() {
    this.fileInput.click();
};
