bool read ( istream& is ) {
    double data[7];
    for ( int i=0; i<7; i++ )
        is>>data[i];
    setEstimate ( SE3 (
            Eigen::Quaterniond ( data[6],data[3], data[4], data[5] ),
            Eigen::Vector3d ( data[0], data[1], data[2] )
    ));
}

bool write ( ostream& os ) const {
    os<<id()<<" ";
    Eigen::Quaterniond q = _estimate.unit_quaternion();
    os<<_estimate.translation().transpose()<<" ";
    os<<q.coeffs()[0]<<" "<<q.coeffs()[1]<<" "<<q.coeffs()[2]<<" "<<q.coeffs()[3]<<endl;
    return true;
}
