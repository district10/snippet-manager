typedef int Point;
typedef Rect_<int> Rect;

typedef struct {
    Point x, y;
} Point2d;

typedef Point2d Triangle[3];    // Triangle tri;    // 6 ints inside

typedef Point2d (*FuncPtr)( Point2d p1, Point2d p2 );
