void calc_quartiles(vector<double> &values, double &q1, double &q2, double &q3)
{
    int Q1 = values.size() / 4;
    int Q2 = values.size() / 2;
    int Q3 = Q1 + Q2;

    nth_element(values.begin(), values.begin() + Q1, values.end());
    nth_element(values.begin() + Q1 + 1, values.begin() + Q2, values.end());
    nth_element(values.begin() + Q2 + 1, values.begin() + Q3, values.end());
    q1 = values[Q1];
    q2 = values[Q2];
    q3 = values[Q3];
}

void calc_mean_stdev(vector<double> &values, double &mean, double &stdev)
{
    mean = accumulate(values.begin(), values.end(), 0.0) / values.size();
    stdev = 0.0;
    if (values.size() >= 2) {
        double sq_sum =
            inner_product(values.begin(), values.end(), values.begin(), 0.0);
        stdev = std::sqrt(sq_sum / values.size() - mean * mean);
    }
}
