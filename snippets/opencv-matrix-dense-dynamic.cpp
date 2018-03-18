class CV_EXPORTS Mat
{
public:
    // ... a lot of methods ...
    ...

    /*! includes several bit-fields:
         - the magic signature
         - continuity flag
         - depth
         - number of channels
     */
    int flags;
    //! the array dimensionality, >= 2
    int dims;
    //! the number of rows and columns or (-1, -1) when the array has more than 2 dimensions
    int rows, cols;
    //! pointer to the data
    uchar* data;

    //! pointer to the reference counter;
    // when array points to user-allocated data, the pointer is NULL
    int* refcount;

    // other members
    ...
};

Mat m(7,7,CV_32FC2,Scalar(1,3));
m.create(100,60,CV_8UC(15));
Mat img(Size(320,240),CV_8UC3);

// create a 100x100x100 8-bit array
int sz[] = {100, 100, 100};
Mat bigCube(3, sz, CV_8U, Scalar::all(0));

M.row(3) = M.row(3) + M.row(5)*3;
Mat M1 = M.col(1);
M.col(7).copyTo(M1);
Mat roi(img, Rect(10,10,100,100));
roi = Scalar(0,255,0);
