var popup = new mapboxgl.Popup({
    closeButton: false
});

popup.setLngLat(e.lngLat)
    .setText(lane.label)
    .addTo(map);
