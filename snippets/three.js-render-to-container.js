container = document.getElementById( 'container' );
if( Detector.webgl ){
    renderer = new THREE.WebGLRenderer({
        antialias: true
     // , alpha: true
    });
} else {
    renderer = new THREE.CanvasRenderer();
}
renderer.setPixelRatio( window.devicePixelRatio );
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.domElement.style.position = 'absolute';
renderer.domElement.style.top = 0;
container.appendChild(renderer.domElement);
