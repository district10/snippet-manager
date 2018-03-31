#include <octomap/octomap.h>    // for octomap
octomap::OcTree tree( 0.05 ); // 参数为分辨率
octomap::Pointcloud cloud;  // the point cloud in octomap

// 将世界坐标系的点放入点云
cloud.push_back( pointWorld[0], pointWorld[1], pointWorld[2] );

// 将点云存入八叉树地图，给定原点，这样可以计算投射线
tree.insertPointCloud( cloud, octomap::point3d( T(0,3), T(1,3), T(2,3) ) );

// 更新中间节点的占据信息并写入磁盘
tree.updateInnerOccupancy();
tree.writeBinary("octomap.bt");
