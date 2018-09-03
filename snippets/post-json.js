var reader = new FileReader();
reader.onload = event => $.ajax({
    type: "POST",
    url: "/to_json",
    data: event.target.result,
    contentType: 'application/json;charset=UTF-8',
    success: data => load_json(data, filename),
});
reader.readAsText(file);
