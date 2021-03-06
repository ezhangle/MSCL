@echo off

:BUILD

echo.
echo ********************************
echo Starting MSCL Build...
echo ********************************
echo.

REM change the directory to this file's directory
cd /d %~dp0

set ISHUDSONBUILD=True

REM ==========================================================================
REM PYTHON BUILD
REM ==========================================================================
echo ********************************
echo Building MSCL for Python x64... (bjam)
echo ********************************
echo.

SET msclCxxFlags="/bigobj /I""C:/Python27_64/include"" /I"C:/Dev/Lib/boost/boost_1_61_0""
IF NOT [%1]==[] SET msclCxxFlags=%1
IF [%1]==["none"] SET msclCxxFlags=" "

SET msclLinkFlags="/LIBPATH:""C:/Python27_64/libs"" /LIBPATH:"C:/Dev/Lib/boost/boost_1_61_0/lib64-msvc-14.0" libboost_system-vc140-mt-s-1_61.lib"
IF NOT [%2]==[] SET msclLinkFlags=%2
IF [%2]==["none"] SET msclLinkFlags=" "

echo msclCxxFlags: %msclCxxFlags%
echo msclLinkFlags: %msclLinkFlags%

REM change to the directory of Jamroot
cd ..\

REM for now, bjam needs this folder to exist
echo Creating the build\swig-python directory
mkdir build\swig-python

REM build the python version of MSCL (have to do this twice to copy the .py output file (BUG))
echo Running BJAM (1)
REM linkflags=/SUBSYSTEM:WINDOWS",5.01"
bjam MSCL//stage_python_x64 runtime-link=static link=static release toolset=msvc-14.0 cxxflags=%msclCxxFlags% linkflags=%msclLinkFlags% address-model=64 -j4
echo Running BJAM (2)
bjam MSCL//stage_python_x64 runtime-link=static link=static release toolset=msvc-14.0 cxxflags=%msclCxxFlags% linkflags=%msclLinkFlags% address-model=64 -j4

REM rename _mscl.dll to _mscl.pyd 
echo Renaming _mscl.dll to _mscl.pyd
move /y Output\Python\x64\_mscl.dll Output\Python\x64\_mscl.pyd

REM delete the unnecessary _mscl.lib that is leftover in the Python output folder
echo Deleting extra _mscl.lib 
del Output\Python\x64\_mscl.lib

cd /d %~dp0

echo DONE BUILDING MSCL (end build_Python_x64.cmd)

:end