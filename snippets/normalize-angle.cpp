// Bring the 'difference' between two angles into [-pi; pi].
template <typename T>
T NormalizeAngleDifference(T difference) {
  while (difference > M_PI) {
    difference -= 2. * M_PI;
  }
  while (difference < -M_PI) {
    difference += 2. * M_PI;
  }
  return difference;
}

