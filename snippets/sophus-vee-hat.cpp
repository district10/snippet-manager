Sophus::SO3::vee( Sophus::SO3::hat(so3) ).transpose() << endl;

Eigen::Vector3d update_so3(1e-4, 0, 0); // update
Sophus::SO3 SO3_updated = Sophus::SO3::exp(update_so3) * SO3_R;
