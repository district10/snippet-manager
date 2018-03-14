var gui = new dat.GUI(); gui.closed = true;

gui.add(config, 'toggleCamera').name("切换相机");
gui.add(config, 'autorot').min(-5).max(+5).step(1).listen().name("自动浏览");
gui.add(config, 'fov').min(10).max(150).step(1).listen().name("视场角").onChange(function(value){
    if (config.fov !== camera.fov) {
        camera.fov = value;
        camera.updateProjectionMatrix();
    }
});
var advanced = gui.addFolder('高级设置');
advanced.add(config, 'nsep').min(2).max(25).step(1).listen().name("face #sep").onChange(function(){
    config.lastProgress = -1.0;
});
var links = gui.addFolder('链接');
var link = {
    "README": function() { window.location = "README.html"; },
    "dyna_texture": function() { window.location = "dyna_texture.html"; }
};
links.add(link, 'dyna_texture').name("动态全景图方案");
