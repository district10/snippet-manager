// 定义点云使用的格式：这里用的是XYZRGB
typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloud;

// 新建一个点云
PointCloud::Ptr pointCloud( new PointCloud );

PointCloud::Ptr current( new PointCloud );
PointCloud::Ptr tmp ( new PointCloud );
pcl::StatisticalOutlierRemoval<PointT> statistical_filter;
statistical_filter.setMeanK(50);
statistical_filter.setStddevMulThresh(1.0);
statistical_filter.setInputCloud(current);  // current -> tmp
statistical_filter.filter( *tmp );
(*pointCloud) += *tmp;                      // tmp -> pointCloud

pointCloud->is_dense = false;
cout << "点云共有" << pointCloud->size() << "个点." << endl;

// voxel filter
pcl::VoxelGrid<PointT> voxel_filter;
voxel_filter.setLeafSize( 0.01, 0.01, 0.01 );       // resolution
PointCloud::Ptr tmp ( new PointCloud );
voxel_filter.setInputCloud( pointCloud );
voxel_filter.filter( *tmp );
tmp->swap( *pointCloud );

cout << "滤波之后，点云共有" << pointCloud->size() << "个点." << endl;

pcl::io::savePCDFileBinary("map.pcd", *pointCloud );
