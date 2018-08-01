#pragma once

#include <cstdio>
#include <proj_api.h>
#include <vector>
#include <iostream>

const static projPJ pj_ecef =
    pj_init_plus("+proj=geocent +ellps=WGS84 +datum=WGS84");
const static projPJ pj_lla =
    pj_init_plus("+proj=longlat +ellps=WGS84 +datum=WGS84");

static projPJ pj_utm_in_zone(int zone)
{
    static char buf[256];
    sprintf(buf, "+proj=utm +zone=%d +ellps=WGS84", zone);
    return pj_init_plus(buf);
}

std::vector<double> utm2ecef(std::vector<double> v, int zone)
{
    auto pj_utm = pj_utm_in_zone(zone);
    pj_transform(pj_utm, pj_ecef, 1, 1, &v[0], &v[1], &v[2]);
    return v;
}

std::vector<double> utm2lla(std::vector<double> v, int zone)
{
    auto pj_utm = pj_utm_in_zone(zone);
    pj_transform(pj_utm, pj_lla, 1, 1, &v[0], &v[1], &v[2]);
    v[0] *= RAD_TO_DEG;
    v[1] *= RAD_TO_DEG;
    return v;
}

std::vector<double> ecef2utm(std::vector<double> v, int &zone)
{
    double lon = atan2(v[1], v[0]) * RAD_TO_DEG;
    zone = int((lon + 180.0) / 6.0) + 1;
    auto pj_utm = pj_utm_in_zone(zone);
    pj_transform(pj_ecef, pj_utm, 1, 1, &v[0], &v[1], &v[2]);
    return v;
}

std::vector<double> ecef2lla(std::vector<double> v)
{
    pj_transform(pj_ecef, pj_lla, 1, 1, &v[0], &v[1], &v[2]);
    v[0] *= RAD_TO_DEG;
    v[1] *= RAD_TO_DEG;
    return v;
}

std::vector<double> lla2utm(std::vector<double> v, int &zone)
{
    if (zone < 0) {
        zone = int((v[0] + 180.0) / 6.0) + 1;
    }
    auto pj_utm = pj_utm_in_zone(zone);
    v[0] *= DEG_TO_RAD;
    v[1] *= DEG_TO_RAD;
    pj_transform(pj_lla, pj_utm, 1, 1, &v[0], &v[1], &v[2]);
    return v;
}

std::vector<double> lla2ecef(std::vector<double> v)
{
    v[0] *= DEG_TO_RAD;
    v[1] *= DEG_TO_RAD;
    pj_transform(pj_lla, pj_ecef, 1, 1, &v[0], &v[1], &v[2]);
    return v;
}
