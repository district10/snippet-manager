inline Vector6d toMinimalVector() const{
    Vector6d v;
    v[0]=_t(0);
    v[1]=_t(1);
    v[2]=_t(2);
    v[3]=_r.x();
    v[4]=_r.y();
    v[5]=_r.z();
    return v;
}

inline void fromMinimalVector(const Vector6d& v){
    double w = 1.-v[3]*v[3]-v[4]*v[4]-v[5]*v[5];
    if (w>0){
        _r=Quaterniond(sqrt(w), v[3], v[4], v[5]);
    } else {
        _r=Quaterniond(0, -v[3], -v[4], -v[5]);
    }
    _t=Vector3d(v[0], v[1], v[2]);
}
