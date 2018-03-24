double Median(std::vector<double> &data) {
  auto mid_point = data.begin();
  std::advance(mid_point, data.size()/2);
  std::nth_element(data.begin(), mid_point, data.end());
  return *mid_point;
}
