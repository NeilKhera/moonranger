cmake_minimum_required(VERSION 2.6.4)
project(PUBLISHER C)

set(CMAKE_CXX_STANDARD 11)

include_directories(../inc)
include_directories(fsw/src)
include_directories(fsw/tables)
aux_source_directory(fsw/src APP_SRC_FILES)

add_cfe_app(publisher ${APP_SRC_FILES})

#add_cfe_tables(publisher "fsw/tables/publisher_tbl.c")

