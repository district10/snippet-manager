function calGCSDistanceByMeter(p1, p2) {
    let a = 6378137
    let f = 1 / 298.257223563
    let b = a * (1 - f)
    let e1_2 = f + f * b / a
    let deg_to_rad = Math.PI / 180
    let ref_lat = p1[1] * deg_to_rad
    let sinphi2 = Math.sin(ref_lat) * Math.sin(ref_lat)
    let m = a * (1 - e1_2) / Math.pow(1 - e1_2 * sinphi2, 1.5)
    let r = a * Math.cos(ref_lat) / Math.sqrt(1 - e1_2 * sinphi2)
    let dlon = (p2[0] - p1[0]) * deg_to_rad * r
    let dlat = (p2[1] - p1[1]) * deg_to_rad * m
    return Math.sqrt(dlon * dlon + dlat * dlat)
}
