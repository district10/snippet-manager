// stack 是个黑盒，只能完全拿一个拷贝
for( std::stack<int> dump = stack; !dump.empty(); dump.pop() ) {
    std::cout << dump.top() << '\n';
}

// deque 可以 iterate
for( deque<int>::iterator it = q.begin(); it != q.end(); ++it )
    cout << *it << endl;
}
