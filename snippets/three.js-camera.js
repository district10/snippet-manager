this.camera = new THREE.PerspectiveCamera(this.fov, window.innerWidth / window.innerHeight, 1, 1000);
this.cameraHelper = new THREE.CameraHelper(this.camera);
this.cameraHelper.visible = false;
