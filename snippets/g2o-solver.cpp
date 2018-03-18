// traits
template <int _PoseDim, int _LandmarkDim>
struct BlockSolverTraits
{
    static const int PoseDim = _PoseDim;
    static const int LandmarkDim = _LandmarkDim;
    typedef Eigen::Matrix<double, PoseDim, PoseDim, Eigen::ColMajor> PoseMatrixType;
    typedef Eigen::Matrix<double, LandmarkDim, LandmarkDim, Eigen::ColMajor> LandmarkMatrixType;
    typedef Eigen::Matrix<double, PoseDim, LandmarkDim, Eigen::ColMajor> PoseLandmarkMatrixType;
    typedef Eigen::Matrix<double, PoseDim, 1, Eigen::ColMajor> PoseVectorType;
    typedef Eigen::Matrix<double, LandmarkDim, 1, Eigen::ColMajor> LandmarkVectorType;

    typedef SparseBlockMatrix<PoseMatrixType> PoseHessianType;
    typedef SparseBlockMatrix<LandmarkMatrixType> LandmarkHessianType;
    typedef SparseBlockMatrix<PoseLandmarkMatrixType> PoseLandmarkHessianType;
    typedef LinearSolver<PoseMatrixType> LinearSolverType;
};

// block solver
template <typename Traits>
class BlockSolver: public BlockSolverBase {
    public:
        // 从 traits 里面提取出类型和常量
        static const int PoseDim = Traits::PoseDim;
        static const int LandmarkDim = Traits::LandmarkDim;
        typedef typename Traits::PoseMatrixType PoseMatrixType;
        typedef typename Traits::LandmarkMatrixType LandmarkMatrixType;
        typedef typename Traits::PoseLandmarkMatrixType PoseLandmarkMatrixType;
        typedef typename Traits::PoseVectorType PoseVectorType;
        typedef typename Traits::LandmarkVectorType LandmarkVectorType;

        typedef typename Traits::PoseHessianType PoseHessianType;
        typedef typename Traits::LandmarkHessianType LandmarkHessianType;
        typedef typename Traits::PoseLandmarkHessianType PoseLandmarkHessianType;
        typedef typename Traits::LinearSolverType LinearSolverType;
        /**
         * allocate a block solver ontop of the underlying linear solver.
         * NOTE: The BlockSolver assumes exclusive access to the linear solver and will therefore free the pointer
         * in its destructor.
         */
        BlockSolver(LinearSolverType* linearSolver);
        ~BlockSolver();
        // ...
}

// block                                 pose-dim, landmark-dim
typedef g2o::BlockSolver<g2o::BlockSolverTraits<6,1>> DirectBlock;  // 求解的向量是6＊1的
DirectBlock::LinearSolverType* linearSolver = new g2o::LinearSolverDense< DirectBlock::PoseMatrixType > ();
