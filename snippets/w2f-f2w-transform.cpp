static void transformW2F(Eigen::Matrix<number_t,3,4> &m,
        const Vector3 &trans,
        const Quaternion &qrot)
{
    m.block<3,3>(0,0) = qrot.toRotationMatrix().transpose();
    m.col(3).setZero();         // make sure there's no translation, 这个好机智
    Vector4 tt;
    tt.head(3) = trans;
    tt[3] = 1.0;
    m.col(3) = -m*tt; // 直接用 m 来算，不用自己新建一个 R^T
}

static void transformF2W(Eigen::Matrix<number_t,3,4> &m,
        const Vector3 &trans,
        const Quaternion &qrot)
{
    m.block<3,3>(0,0) = qrot.toRotationMatrix();
    m.col(3) = trans;
}
