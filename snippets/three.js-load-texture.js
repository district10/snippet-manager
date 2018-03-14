function loadTexture(url) {
    if (!url) { return; }
    config.hideDatGui();
    var loadWhenReady = function(url) {
        if (material && material.map && material.map.image) {
            $("#pic")[0].src = $("#pic").parent()[0].href = url;
            material.map.image.src = url;
            material.map.needsUpdate = true;
            hideLoading();
        } else {
            setTimeout(function() { loadWhenReady(url); }, 100);
        }
    }
    loadWhenReady(url);
}
