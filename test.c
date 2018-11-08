//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    
    int input;
    string file_name;
    cout << "----------------------------\n"<< endl;
    
    cout << "1. Launch LiDAR to scan\n"<< endl;
    cout << "2. Record Scan data \n"<< endl;
    cout << "3. Process the scanned data format\n"<< endl;
    cout << "4. Launch video recorder\n"<< endl;
    cout << "5. Process the recorded bag to video \n"<< endl;
    cout << "6. Stop the whole scanning system\n"<< endl;
    cout << "7. Eliminate previous scanned and recorded video data\n"<<endl;
//    cout <<"8. Root permisson\n"<<endl;
    
    //cout << "5. Permission to access Scanned Data\n"<< endl;
        
	//cout << "5. Tranfer scanned data to remote machine\n"<<endl;
    cout << "----------------------------\n"<< endl;
    cin >> input;
  
    switch (input)
 	{	
		case 1:
		  system("roslaunch velodyne_pointcloud VLP16_points.launch");
		//xterm -hold -e "roslaunch velodyne_pointcloud VLP16_points.launch"
		break;
		
		case 2:
		//cout <<"please enter file name to save data/n"<<endl;
		//getchar();
		//getline(cin,file_name);
		

			system("rosrun rosbag record --duration=10  -O ./share/ScannedData.bag /velodyne_points");
			cout<<" Scanned data is getting converted to PCD format....!!"<<endl;
			system("rosrun pcl_ros bag_to_pcd ./share/ScannedData.bag /velodyne_points ./share/ScannedData");
	
			
		//system("rosrun rosbag record --duration=30  -O /share/test1.bag /velodyne_points");
		break;
                case 3:
			cout<<" Scanned data is getting converted to PCD format....!! \n"<<endl;
			system("rosrun pcl_ros bag_to_pcd ./share/ScannedData.bag /velodyne_points ./share/ScannedData");
		break;
		case 4:
		     //  system("sudo -s");
		       system("roslaunch dji_sdk_read_cam manifold_cam.launch");
		break;		
		case 5: 
		       cout<<"video is getting recorded!!"<<endl;
		       //system("rosrun rosbag record --duration=10  -O /home/ubuntu/share/bag_video_fast/recordFile/record1.bag /dji_sdk/image_raw");
			
			system("rosrun rosbag record --duration=10  -O /home/ubuntu/share/bag_video_fast/recordFile/record1.bag /dji_sdk/image_raw");
		       	
                       //system("rosrun rosbag record --duration=10  -O /home/ubuntu/share/bag_video/recordFile/record1.bag /dji_sdk/image_raw");
		       cout<<"video conversion is taking place"<<endl;
		       //system("python /home/ubuntu/share/bag_video/bag2video.py -o /home/ubuntu/share/bag_video/recordFile/record1.avi -v --encoding bgr8 /dji_sdk/image_raw /home/ubuntu/share/bag_video/recordFile/record1.bag");

		system("python /home/ubuntu/share/bag_video_fast/rosbag2video.py --fps 25 -o /home/ubuntu/share/bag_video_fast/recordFile/record1.mp4 -t /dji_sdk/image_raw /home/ubuntu/share/bag_video_fast/recordFile/record1.bag");
n /home/ubuntu/share/bag_video_fast/rosbag2video.py --fps 25 -o /home/ubuntu/share/bag_video_fast/recordFile/record1.mp4 -t /dji_sdk/image_raw /home/ubuntu/share/bag_video_fast/recordFile/record1.bag"
		break;
		
		case 6:
			system(" rosnode kill -a");
		break;

		case 8:
			//system("sudo chmod -R 777 /home/ubuntu/share/");
			system("sudo -s");
		break;
		
		case 7: 
			cout <<"Data is being Eliminated ...........\n"<< endl;
			system("rm /home/ubuntu/share/ScannedData/*.*");
                        system("rm /home/ubuntu/share/bag_video_fast/recordFile/*.*");
			
			//system("rm -rf /home/ubuntu/share/ScannedData");
			
			//system("sudo scp launchVelo.sh VE LAB@192.168.0.28:/Users/pavan");
			//cout << "Transfer completed"<< endl;
		break;
//case 9: system(
		
		default:
		break;
		
		
	}
}

