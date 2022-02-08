ROS2 설치 방법
=============

###시스템에 ROS 2 apt 저장소를 추가합니다. GPG 키를 인증합니다.
<code>
$ sudo apt update && sudo apt install curl gnupg lsb-release
$ sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
</code>
###소스 목록에 저장소를 추가합니다.
<code>
$ echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
</code>
###ROS2 데스크톱 버전 설치합니다.
<code>
$ sudo apt update
$ sudo apt install ros-galactic-desktop
</code>
