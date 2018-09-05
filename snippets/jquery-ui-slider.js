// <script src='res/jquery-ui.min.js'></script>
// <link href='res/jquery-ui.min.css' rel='stylesheet' />
// <div id="slider-vertical" style="height:200px; position: absolute; left: 10px; bottom: 80px"></div>

$("#slider-vertical").slider({
    orientation: "vertical",
    range: "min",
    min: 1,
    max: 5,
    value: 1,
    slide: function (event, ui) {
        // ui.value
    },
    stop: function (event, ui) {
    }
});
