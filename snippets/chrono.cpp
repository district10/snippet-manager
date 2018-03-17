chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
// ...
chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>> ( t2-t1 );
cout << time_used.count() << endl; // seconds
