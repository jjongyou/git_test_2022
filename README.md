ROS2 설치 방법
=============

### 시스템에 ROS 2 apt 저장소를 추가 및 GPG 키를 인증
```
$ sudo apt update && sudo apt install curl gnupg lsb-release
$ sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```
### 소스 목록에 저장소를 추가
```
$ echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
### ROS2 데스크톱 버전 설치
```
$ sudo apt update
$ sudo apt install ros-galactic-desktop
```
### ROS2 개발 Tool 설치
```
$ sudo apt update
$ sudo apt install -y python3-pip
$ sudo apt install -y build-essential
$ sudo apt install -y python3-colcon-common-extensions
$ pip3 install -U argcomplete
```
### 환경 설정
```
$ echo "source /opt/ros/galactic/setup.bash" >> ~/.bashrc
```
### ROS2 build test & work space 만들기
```
$ mkdir -p colcon_ws/src
$ colcon build --symlink-install
```
### 빌드 완료 후 환경 변수 추가
```
$ echo ". ~/colcon_ws/install/local_setup.bash" >> ~/.bashrc
```
### 노드 정상 실행 테스트
```
$ ros2 run demo_nodes_py listener
```
## ROS2 명령어 모음
### Node 실행
```
$ ros2 run < package_name > < node_name >
# Example
$ ros2 run yrlros2 yrl_lidar
```
### 특정 Node parameter 확인
```
$ ros2 param list /< node_name >
# Example
$ ros2 param list /yrl_lidar
```
### 특정 Node parameter 변경
```
$ ros2 param set /< node_name > < parameter_name > < parameter_value >
# Example
$ ros2 param set /yrl_lidar lidar_IP 192.168.1.13
```
### 특정 Node yaml file load
```
$ ros2 param load /< node_name > < path_to_yaml_file >
# Example
$ ros2 param load /yrl_lidar ~/colcon_ws/src/yrlros2/cfg/lidar_params.yaml
```
### Node 실행 시, 직접 parameter변수 값 변경법
```
$ ros2 run < package_name > < node_name > --ros-args -p < parameter_name >:=< parameter_value >
# Example
$ ros2 run yrlros2 yrl_lidar --ros-args -p lidar_IP:="192.168.1.13" -p max_Vertical_Angle:=20 -p extrinsic_Transform:="[0.0, 0.0, 1.0, 0.0, 0.0, 0.0]"
```
### Node 실행 시, yaml file load 하는 방법
```
$ ros2 run < package_name > < node_name > --ros-args --params-file < path_to_yaml_file >
# Example
$ ros2 run yrlros2 yrl_lidar --ros-args --params-file ~/colcon_ws/src/yrlros2/cfg/lidar_params.yaml
```

### roslaunch 로 실행하는 방법
```
$ ros2 launch < package_name > < launch_file_name >
# Example
$ ros2 launch yrlros2 yrl_lidar.launch.py
```

### 환경 설정 bashrc 설정법
```
$ echo "ROS_VERSION=2"  >> ~/.bashrc
$ echo "ROS_PYTHON_VERSION=3"  >> ~/.bashrc
$ echo "ROS_DISTRO=galactic"  >> ~/.bashrc
```
#### alias를 이용하여 간편한 명령어 이용
```
$ echo "alias cs='cd ~/colcon_ws/src'"  >> ~/.bashrc
$ echo "alias cw='cd ~/colcon_ws"  >> ~/.bashrc
$ echo "alias cm='cd ~/colcon_ws&& colcon build --symlink-install"  >> ~/.bashrc
```
