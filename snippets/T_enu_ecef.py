#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys
import glob
sys.path.append(os.path.abspath(os.path.join(
    os.path.dirname(__file__), os.path.pardir)))

import transforms3d

def from_R_t(R: np.ndarray, t: np.ndarray) -> np.ndarray:
    return np.hstack((np.copy(R), np.copy(t).reshape(3, 1)))


def from_T(T: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:
    R = T[:3, :3]
    t = T[:, 3]
    return (R, t)

def inv_T(T: np.ndarray) -> np.ndarray:
    R, t = from_T(T)
    t = -R.T.dot(t)
    return from_R_t(R.T, t)

def lon_lat_to_R_enu_ecef(lon: float, lat: float) -> np.ndarray:
    lon = math.radians(lon)
    lat = math.radians(lat)
    s1 = math.sin(math.pi / 4.0 + lon / 2.0)
    c1 = math.cos(math.pi / 4.0 + lon / 2.0)
    s2 = math.sin(math.pi / 4.0 - lat / 2.0)
    c2 = math.cos(math.pi / 4.0 - lat / 2.0)
    return transforms3d.quaternions.quat2mat([c1 * c2, -c1 * s2, -s1 * s2, -s1 * c2])

def get_T_enu_ecef(lon: float, lat: float, alt: float) -> np.ndarray:
    R = lon_lat_to_R_enu_ecef(lon, lat)
    Ow = lla2ecef([lon, lat, alt])
    t = -R.dot(Ow)
    return from_R_t(R, t)

def get_T_ecef_enu(lon: float, lat: float, alt: float) -> np.ndarray:
    T_enu_ecef = get_T_enu_ecef(lon, lat, alt)
    return inv_T(T_enu_ecef)

