cmake_minimum_required(VERSION 3.21)
project(hands-timesync VERSION 0.1)

find_package(Qt6 COMPONENTS Core REQUIRED)

add_executable(hands-timesync handsTimesync.cpp)
target_link_libraries(hands-timesync PRIVATE Qt::Core)
install(TARGETS hands-timesync DESTINATION bin)
install(FILES hands-timesync.service hands-timesync.timer
		DESTINATION /usr/lib/systemd/system)
