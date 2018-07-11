// demo from:
//      https://stackoverflow.com/questions/47653386/how-to-use-boostgeometryrtree-with-glmvec3-as-a-custom-point-type
#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/register/point.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

namespace glm
{
    struct vec3 {
        double x, y, z;
        vec3(double x_, double y_, double z_) { x = x_; y = y_; z = z_; }
    };
}

BOOST_GEOMETRY_REGISTER_POINT_3D(glm::vec3, double, bg::cs::cartesian, x, y, z)

#include <iostream>
int main() {
    using IndexedPoint = std::pair<glm::vec3, uint32_t>;
    using RTree = boost::geometry::index::rtree<IndexedPoint, boost::geometry::index::rstar<8>>;

    RTree rtree;
    rtree.insert({glm::vec3(1,1,1), 1});
    rtree.insert({glm::vec3(2,2,2), 2});
    rtree.insert({glm::vec3(3,3,3), 3});
    rtree.insert({glm::vec3(4,4,4), 4});

    auto q = bgi::nearest(glm::vec3(2.9, 2.9, 2.9), 99);

    auto it = rtree.qbegin(q);
    auto p = it->first;
    std::cout << "Nearest: # " << it->second << " (" << p.x << ", " << p.y << " " << p.z << ")\n";
}
