v.clear();                // the performance depends on how's your dtor
// or
vector<T>().swap( v );      // clear x reallocating
