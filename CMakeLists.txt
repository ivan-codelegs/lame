cmake_minimum_required( VERSION 3.18 )

project( mp3lame )

if( NOT WIN32 )
   message( FATAL_ERROR "This cmake file is only for Windows!" )
endif()

if( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
   set( STATIC_BUILD FALSE CACHE BOOL "" )
else()
   set( STATIC_BUILD TRUE CACHE BOOL "" )
endif()

if( "${CMAKE_SIZEOF_VOID_P}" STREQUAL "4" )
   set( ARCH x86 )
else()
   set( ARCH x86_64 )
endif()

if( ${STATIC_BUILD} )
   add_library( ${PROJECT_NAME} STATIC )
else()
   add_library( ${PROJECT_NAME} SHARED )
endif()

target_include_directories( ${PROJECT_NAME} PRIVATE
   mpglib
   include
   libmp3lame
   windows/${ARCH}
)

file( GLOB_RECURSE LAME_HEADERS
   mpglib/*.h
   include/*.h
   libmp3lame/*.h
   windows/${ARCH}/*.h
)


target_sources( ${PROJECT_NAME} PRIVATE
   libmp3lame/bitstream.c
   libmp3lame/encoder.c
   libmp3lame/fft.c
   libmp3lame/gain_analysis.c
   libmp3lame/id3tag.c
   libmp3lame/lame.c
   libmp3lame/newmdct.c
   libmp3lame/psymodel.c
   libmp3lame/quantize.c
   libmp3lame/quantize_pvt.c
   libmp3lame/vector/xmm_quantize_sub.c
   libmp3lame/set_get.c
   libmp3lame/vbrquantize.c
   libmp3lame/reservoir.c
   libmp3lame/tables.c
   libmp3lame/takehiro.c
   libmp3lame/util.c
   libmp3lame/mpglib_interface.c
   libmp3lame/VbrTag.c
   libmp3lame/presets.c
   libmp3lame/version.c
   mpglib/common.c
   mpglib/dct64_i386.c
   mpglib/decode_i386.c
   mpglib/layer1.c
   mpglib/layer2.c
   mpglib/layer3.c
   mpglib/tabinit.c
   mpglib/interface.c
   ${LAME_HEADERS}
)

set_target_properties( ${PROJECT_NAME} PROPERTIES
     C_STANDARD 17
   CXX_STANDARD 17
)

target_compile_definitions( ${PROJECT_NAME} PRIVATE
   -DHAVE_CONFIG_H
   -DHAVE_MPGLIB
)

if( ${STATIC_BUILD} )
   set_property( TARGET ${PROJECT_NAME} PROPERTY
      MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
   )
else()
   target_sources( ${PROJECT_NAME} PRIVATE include/lame.def )
endif()
