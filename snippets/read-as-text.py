function loadfile(file, filename) {
    var reader = new FileReader();
    reader.onload = event => $.ajax({
        type: "POST",
        url: "/to_geojson",
        data: event.target.result,
        contentType: "application/json;charset=UTF-8",
        success: data => load_geojson(data, filename),
    });
    reader.readAsText(file);
};
