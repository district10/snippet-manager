// https://stackoverflow.com/questions/9605556/how-to-project-a-point-onto-a-plane-in-3d
vector<double> project_to_plane(
        const vector<double> &xyz,
        const vector<double> &v)
{
    cv::Mat norm = cv::Mat(v).clone();
    norm /= -utils::distance(norm);
    cv::Mat point = cv::Mat(xyz).clone();
    double dist = norm.dot(point - cv::Mat(v));
    cv::Mat projected = point - dist * norm;
    vector<double> ret;
    projected.copyTo(ret);
    return ret;
}
