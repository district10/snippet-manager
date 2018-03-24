std::mutex mMutex;
{
    unique_lock<mutex> lock(m);
    // ...
}
