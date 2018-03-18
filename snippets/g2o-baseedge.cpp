namespace g2o {
  template <int D, typename E>
  class BaseEdge : public OptimizableGraph::Edge
  {
    public:

      static const int Dimension = D;
      typedef E Measurement;
      typedef Eigen::Matrix<double, D, 1, Eigen::ColMajor> ErrorVector;
      typedef Eigen::Matrix<double, D, D, Eigen::ColMajor> InformationType;

      BaseEdge() : OptimizableGraph::Edge()
      {
        _dimension = D;
      }

      virtual ~BaseEdge() {}

      virtual double chi2() const
      {
        return _error.dot(information()*_error);
      }
      // ...
    }

  template <int D, typename E, typename VertexXi>
  class BaseUnaryEdge : public BaseEdge<D,E>
  {
    public:
      static const int Dimension = BaseEdge<D, E>::Dimension;
      typedef typename BaseEdge<D,E>::Measurement Measurement;
      typedef VertexXi VertexXiType;
      typedef typename Eigen::Matrix<double, D, VertexXiType::Dimension, D==1?Eigen::RowMajor:Eigen::ColMajor>::AlignedMapType JacobianXiOplusType;
      typedef typename BaseEdge<D,E>::ErrorVector ErrorVector;
      typedef typename BaseEdge<D,E>::InformationType InformationType;

      BaseUnaryEdge() : BaseEdge<D,E>(),
        _jacobianOplusXi(0, D, VertexXiType::Dimension)
      {
        _vertices.resize(1);
      }
      // ...
  }
}
