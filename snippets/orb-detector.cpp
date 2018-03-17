std::vector<KeyPoint> keypoints_1, keypoints_2;
Mat descriptors_1, descriptors_2;
Ptr<FeatureDetector> detector = ORB::create();
Ptr<DescriptorExtractor> descriptor = ORB::create(); // FastFeatureDetector::create();

detector->detect ( img_1, keypoints_1 ); // oriented fast: img -> keypoints
descriptor->compute ( img_1, keypoints_1, descriptors_1 ); // img, keypoints -> descriptors
drawKeypoints( img_1, keypoints_1, outimg1);

vector<DMatch> matches;
Ptr<DescriptorMatcher> matcher  = DescriptorMatcher::create ( "BruteForce-Hamming" );
// brute force matcher: BFMatcher matcher ( NORM_HAMMING );
// `BruteForce` (it uses L2 )
// `BruteForce-L1`
// `BruteForce-Hamming`
// `BruteForce-Hamming(2)`
// `FlannBased`
matcher->match ( descriptors_1, descriptors_2, matches ); // descriptors -> matches

min_dist = min_element( matches.begin(), matches.end(), [](const DMatch& m1, const DMatch& m2) {return m1.distance<m2.distance;} )->distance;
max_dist = max_element( matches.begin(), matches.end(), [](const DMatch& m1, const DMatch& m2) {return m1.distance<m2.distance;} )->distance;

std::vector< DMatch > good_matches;
for ( int i = 0; i < descriptors_1.rows; i++ ) {
    if ( matches[i].distance <= max ( 2*min_dist, 30.0 ) ) {
        good_matches.push_back ( matches[i] );
    }
}

drawMatches ( img_1, keypoints_1, img_2, keypoints_2, matches, img_match );
waitKey(0);
