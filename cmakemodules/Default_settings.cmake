SET( ILCSOFT_CMAKE_MODULES_ROOT ${PANDORA_CMAKE_MODULE_PATH} )

#OPTION( BUILD_SHARED_LIBS "Set to OFF to build static libraries" ON )
#SET( BUILD_SHARED_LIBS "${BUILD_SHARED_LIBS}" CACHE BOOL "Set to OFF to build static libraries" FORCE )

INCLUDE( MacroAddSharedLibrary )
INCLUDE( MacroInstallSharedLibrary )
INCLUDE( MacroInstallDirectory )
INCLUDE( MacroDisplayStandardVariables )
INCLUDE( MacroGeneratePackageConfigFiles )

INCLUDE( Default_install_prefix )
INCLUDE( Default_build_type )
INCLUDE( Default_library_versioning )
INCLUDE( Default_build_output_directories )
INCLUDE( Default_rpath_settings )
#INCLUDE( Build_32bit_compatible )
