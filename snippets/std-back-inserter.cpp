std::vector<int> to_vector;
std::copy(from_vector.begin(), from_vector.end(),
        std::back_inserter(to_vector));   // 从后面插入

std::vector<int> to_vector(from_vector.size());         // 一定要自己把 size 调好。
std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());

// 直接复制
std::vector<int> to_vector = from_vector;
