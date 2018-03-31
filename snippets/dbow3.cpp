// save
DBoW3::Vocabulary vocab;
vocab.create( descriptors ); // 用一个 vector 的 descriptor 来生成词带
// vocabulary info:
// Vocabulary: k = 10, L = 5, Weighting = tf-idf,
//      Scoring = L1-norm,
//      Number of words = 4970
cout << "vocabulary info: " << vocab << endl;
vocab.save( "vocabulary__" + to_string(time(0)) + ".yml.gz" ); // timestamp

// load
DBoW3::Vocabulary vocab("vocabulary.yml.gz");
if ( vocab.empty() ) { return 1; }

// compare two img (descriptors)
DBoW3::BowVector v1, v2;
vocab.transform( descriptor1, v1 );
vocab.transform( descriptor2, v2 );
double score = vocab.score(v1, v2);
cout << "image 1 vs image 2: " << score << endl;

// compare with db
DBoW3::Database db( vocab, false, 0);
for ( int i=0; i<descriptors.size(); i++ )
    db.add(descriptors[i]);
cout<<"database info: "<<db<<endl;
for ( int i=0; i<descriptors.size(); i++ ) {
    DBoW3::QueryResults ret;
    db.query( descriptors[i], ret, 4);      // max result=4
    cout<<"searching for image "<<i<<" returns "<<ret<<endl<<endl;
}
