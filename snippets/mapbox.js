mapboxgl.accessToken = "<token>";
var map = new mapboxgl.Map({
    container: "map",
    style: config.map_style,
    center: [116.17741, 39.87229],
    zoom: 14
});
var scale = new mapboxgl.ScaleControl({
    maxWidth: 80,
    unit: "imperial"
});
map.addControl(scale);
scale.setUnit("metric");
var nav = new mapboxgl.NavigationControl();
map.addControl(nav, "top-left");

map.setZoom(14);
map.flyTo({"center": [lc.center_lla[0], lc.center_lla[1]]});

var container = map.getCanvasContainer();
var svg = d3.select(container).append("svg");
