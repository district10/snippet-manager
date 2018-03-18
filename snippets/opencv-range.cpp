class CV_EXPORTS Range
{
    public:
        Range();
        Range(int _start, int _end);
        Range(const CvSlice& slice);
        int size() const;
        bool empty() const;
        static Range all();
        operator CvSlice() const;

        int start, end;
};

void my_function(..., const Range& r, ....)
{
    if(r == Range::all()) {
        // process all the data
    }
    else {
        // process [r.start, r.end)
    }
}
