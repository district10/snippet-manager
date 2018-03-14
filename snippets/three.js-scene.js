scene = new THREE.Scene();
scene.add(config.cameraHelper);
var geometry = new THREE.SphereGeometry( 500, 64, 32 );
geometry.scale( - 1, 1, 1 );
material = new THREE.MeshBasicMaterial( {
    map: new THREE.TextureLoader().load( config.textureSrc )
} );
var mesh = new THREE.Mesh( geometry, material );
scene.add( mesh );
