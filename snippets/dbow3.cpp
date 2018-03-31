DBoW3::Vocabulary vocab;
vocab.create( descriptors ); // 用一个 vector 的 descriptor 来生成词带
// vocabulary info:
// Vocabulary: k = 10, L = 5, Weighting = tf-idf,
//      Scoring = L1-norm,
//      Number of words = 4970
cout << "vocabulary info: " << vocab << endl;
vocab.save( "vocabulary__" + to_string(time(0)) + ".yml.gz" ); // timestamp
