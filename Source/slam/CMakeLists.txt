
# set module name
SET(MODULE_NAME ${ECHO_GAME_NAME})

MESSAGE( STATUS "Configuring module: ${MODULE_NAME}")

# include directories
INCLUDE_DIRECTORIES( ${ECHO_ROOT_PATH})
INCLUDE_DIRECTORIES( ${ECHO_ROOT_PATH}/thirdparty)
INCLUDE_DIRECTORIES( ${ECHO_ROOT_PATH}/thirdparty/eigen-3.3.3)
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/../)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/ThirdParty/)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/ThirdParty/Sophus)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/ThirdParty/opencv/include)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/ThirdParty/orb-slam3/include)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/ThirdParty/orb-slam3/include/windows)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/boost_1.83.0/src/build/include/boost-1_83)

# link
LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# recursive get all module files
FILE( GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
FILE( GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

SET(ALL_FILES ${HEADER_FILES} ${SOURCE_FILES})

# group files by folder
GROUP_FILES(ALL_FILES ${CMAKE_CURRENT_SOURCE_DIR})

# add macro
IF(ECHO_GAME_SOURCE)
	ADD_DEFINITIONS(-DECHO_GAME_SOURCE)
ENDIF()

# generate module library
ADD_LIBRARY(${MODULE_NAME} ${ALL_FILES} CMakeLists.txt)

# Link thirdparty libraries
TARGET_LINK_LIBRARIES(${MODULE_NAME} DBoW2)
TARGET_LINK_LIBRARIES(${MODULE_NAME} g2o)
TARGET_LINK_LIBRARIES(${MODULE_NAME} orb-slam3)

IF(${ECHO_PLATFORM_WINDOWS})
	TARGET_LINK_LIBRARIES(${MODULE_NAME} 
		debug ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/x64/vc16/lib/opencv_world480d.lib
		optimized ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/x64/vc16/lib/opencv_world480.lib)

	TARGET_LINK_LIBRARIES(${MODULE_NAME} 
		debug ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/openssl-1.1.1t/lib/Win64/VS2015/Release/libssl.lib
		optimized  ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/openssl-1.1.1t/lib/Win64/VS2015/Release/libssl.lib)

	TARGET_LINK_LIBRARIES(${MODULE_NAME} 
		debug ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/openssl-1.1.1t/lib/Win64/VS2015/Release/libcrypto.lib
		optimized  ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/openssl-1.1.1t/lib/Win64/VS2015/Release/libcrypto.lib)

	TARGET_LINK_LIBRARIES(${MODULE_NAME} 
		debug ${ECHO_GAME_ROOT_PATH}/thirdparty/boost_1.83.0/src/build/lib/libboost_serialization-vc143-mt-gd-x64-1_83.lib
		optimized  ${ECHO_GAME_ROOT_PATH}/thirdparty/boost_1.83.0/src/build/lib/libboost_serialization-vc143-mt-gd-x64-1_83.lib)

	# Copy dlls &{CMAKE_BUILD_TYPE} is empty!!!
	ADD_CUSTOM_COMMAND(
		TARGET ${MODULE_NAME} PRE_BUILD 
		COMMAND ${CMAKE_COMMAND} -E copy 
		${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/x64/vc16/bin/opencv_world480d.dll 
		${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/opencv_world480d.dll)

	ADD_CUSTOM_COMMAND(
		TARGET ${MODULE_NAME} PRE_BUILD 
		COMMAND ${CMAKE_COMMAND} -E copy 
		${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv/x64/vc16/bin/opencv_world480.dll 
		${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/opencv_world480.dll)
ENDIF()

# no cmd window
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS /entry:mainCRTStartup")
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /entry:mainCRTStartup")

# set folder
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game")

# log
MESSAGE(STATUS "Configure success!")

