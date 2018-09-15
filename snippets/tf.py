from pyproj import Proj, transform
import math
import sys


def utm2ecef(xyz, zone):
    x, y, z = xyz
    pj_utm = Proj(proj="utm", zone=zone, ellps="WGS84")
    pj_ecef = Proj(proj="geocent", ellps="WGS84", datum="WGS84")
    return transform(pj_utm, pj_ecef, x, y, z)


def utm2lla(xyz, zone):
    x, y, z = xyz
    pj_utm = Proj(proj="utm", zone=zone, ellps="WGS84")
    pj_lla = Proj(proj="longlat", ellps="WGS84", datum="WGS84")
    return transform(pj_utm, pj_lla, x, y, z)


# 3 degree, 3°
# From UTM coordinates (E, N) to latitude, longitude (φ, λ)
def utm3_to_lla(xyz):
    x, y, z = xyz
    pj_utm = Proj(proj="tmerc", lat_0=0, lon_0=117, x_0=500000, y_0=0)
    pj_lla = Proj(proj="longlat", ellps="WGS84", datum="WGS84")
    return transform(pj_utm, pj_lla, x, y, z)


def ecef2utm(xyz):
    x, y, z = xyz
    lon = math.degrees(math.atan2(y, x))
    zone = int((lon + 180.0) / 6.0) + 1
    pj_ecef = Proj(proj="geocent", ellps="WGS84", datum="WGS84")
    pj_utm = Proj(proj="utm", zone=zone, ellps="WGS84")
    return transform(pj_ecef, pj_utm, x, y, z), zone


def ecef2lla(xyz):
    pj_ecef = Proj(proj="geocent", ellps="WGS84", datum="WGS84")
    pj_lla = Proj(proj="longlat", ellps="WGS84", datum="WGS84")
    x, y, z = xyz
    lon, lat, alt = transform(pj_ecef, pj_lla, x, y, z, radians=False)
    return [lon, lat, alt]


def lla2utm(lla):
    lon, lat, alt = lla
    zone = int((lon + 180.0) / 6.0) + 1
    pj_lla = Proj(proj="longlat", ellps="WGS84", datum="WGS84")
    pj_utm = Proj(proj="utm", zone=zone, ellps="WGS84")
    return transform(pj_lla, pj_utm, lon, lat, alt, radians=False), zone


def lla2ecef(lla):
    pj_ecef = Proj(proj="geocent", ellps="WGS84", datum="WGS84")
    pj_lla = Proj(proj="longlat", ellps="WGS84", datum="WGS84")
    lon, lat, alt = lla
    x, y, z = transform(pj_lla, pj_ecef, lon, lat, alt, radians=False)
    return [x, y, z]
