srand ( ( unsigned int ) time ( 0 ) );
if ( rand() > RAND_MAX/5 ) {
} else {
}

float b = 255*float ( rand() ) /RAND_MAX, g, r;
cv::Scalar color(b, g, r);
