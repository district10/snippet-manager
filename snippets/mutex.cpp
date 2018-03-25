std::mutex m;
{
    unique_lock<mutex> lock(m);
    // ...
}
