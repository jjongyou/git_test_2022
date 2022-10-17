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
