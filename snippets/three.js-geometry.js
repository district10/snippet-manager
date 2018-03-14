function newTriangle(a,b,c) { // a,b,c
    var geometry = new THREE.Geometry();
    geometry.vertices.push(a.clone());
    geometry.vertices.push(b.clone());
    geometry.vertices.push(c.clone());
    geometry.faces.push( new THREE.Face3(0,1,2) );
    geometry.updatePosition = function (a,b,c) {
        geometry.vertices[0].copy(a);
        geometry.vertices[1].copy(b);
        geometry.vertices[2].copy(c);
        geometry.verticesNeedUpdate = true;
    };
    return geometry;
}
// face3.geometry.vertices[0].clone().setLength(dualTriMesh.radius),
