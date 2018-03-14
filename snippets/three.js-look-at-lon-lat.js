if (camera.lon > 360) { camera.lon -= 360; }
if (camera.lon <   0) { camera.lon += 360; }
camera.lat = Math.max( - 85, Math.min( 85, camera.lat ) );
var phi = THREE.Math.degToRad( 90 - camera.lat );
var theta = THREE.Math.degToRad( camera.lon );
camera.target.x = 500 * Math.sin( phi ) * Math.cos( theta );
camera.target.y = 500 * Math.cos( phi );
camera.target.z = 500 * Math.sin( phi ) * Math.sin( theta );
camera.lookAt( camera.target.add(camera.position) );
