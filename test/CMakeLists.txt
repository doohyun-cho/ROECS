ADD_EXECUTABLE(initializer_test initializer_test.cpp)
TARGET_LINK_LIBRARIES( initializer_test dynamic_adjustment)


ADD_EXECUTABLE(direct_unary_edge_test direct_unary_edge_test.cpp)
TARGET_LINK_LIBRARIES( direct_unary_edge_test dynamic_adjustment)


ADD_EXECUTABLE(frame_loader_test frame_loader_test.cpp)
TARGET_LINK_LIBRARIES( frame_loader_test dynamic_adjustment)


ADD_EXECUTABLE(surround_view_test surround_view_test.cpp)
TARGET_LINK_LIBRARIES( surround_view_test dynamic_adjustment)


ADD_EXECUTABLE(surround_multi_test surround_multi_test.cpp)
TARGET_LINK_LIBRARIES( surround_multi_test dynamic_adjustment)


ADD_EXECUTABLE(variance_test variance_test.cpp)
TARGET_LINK_LIBRARIES( variance_test dynamic_adjustment)



ADD_EXECUTABLE(lk_test lk_test.cpp)
TARGET_LINK_LIBRARIES( lk_test dynamic_adjustment)


ADD_EXECUTABLE(homography_test homography_test.cpp)
TARGET_LINK_LIBRARIES( homography_test dynamic_adjustment)



ADD_EXECUTABLE(all_surround_view_test all_surround_view_test.cpp)
TARGET_LINK_LIBRARIES( all_surround_view_test dynamic_adjustment)


ADD_EXECUTABLE(all_OECS all_OECS.cpp)
TARGET_LINK_LIBRARIES( all_OECS dynamic_adjustment)


## manually added
list(APPEND CMAKE_MODULE_PATH "~/dev/g2o/cmake_modules")
SET( G2O_DIR ~/dev/g2o/cmake_modules )
include_directories( 
    ${G2O_INCLUDE_DIRS}
)
## manually added

ADD_EXECUTABLE(inverse_depth_test inverse_depth_test.cpp)
target_link_libraries( inverse_depth_test dynamic_adjustment)

ADD_EXECUTABLE(matcher_test matcher_test.cpp)
TARGET_LINK_LIBRARIES( matcher_test dynamic_adjustment)


find_library(G2O_OPENGL_HELPER_LIBRARY g2o_opengl_helper)
# find_package(Glog REQUIRED)
find_library(GLOG_LIBRARY NAMES glog)
ADD_EXECUTABLE(offline_baseline_test offline_baseline_test.cpp)
TARGET_LINK_LIBRARIES( offline_baseline_test 
    ${G2O_OPENGL_HELPER_LIBRARY}
    ${GLOG_LIBRARY}
    dynamic_adjustment)
