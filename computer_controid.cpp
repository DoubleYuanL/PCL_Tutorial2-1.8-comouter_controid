#include <pcl/io/pcd_io.h>
#include <pcl/common/centroid.h>
#include <iostream>
int
main(int argc, char ** argv)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	if(pcl::io::loadPCDFile<pcl::PointXYZRGB>(argv[1], *cloud) != 0)
		return -1;
	Eigen::Vector4f centroid;
	pcl::compute3DCentroid(*cloud, centroid);
	std::cout<<"the xyz coordinates of the centorid are ("
			<<centroid[0] << ","
			<<centroid[1] << ","
			<<centroid[2] << ")"<<std::endl;
	return 0;
}
