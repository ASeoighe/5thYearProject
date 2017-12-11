#!/usr/bin/env python
"""
The script builds OpenCV.framework for iOS.
The built framework is universal, it can be used to build app and run it on either iOS simulator or real device.

Usage:
    ./build_framework.py <outputdir>

By cmake conventions (and especially if you work with OpenCV repository),
the output dir should not be a subdirectory of OpenCV source tree.

Script will create <outputdir>, if it's missing, and a few its subdirectories:

    <outputdir>
        build/
            iPhoneOS-*/
               [cmake-generated build tree for an iOS device target]
<<<<<<< HEAD
            iPhoneSimulator/
=======
            iPhoneSimulator-*/
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
               [cmake-generated build tree for iOS simulator]
        opencv2.framework/
            [the framework content]

The script should handle minor OpenCV updates efficiently
- it does not recompile the library from scratch each time.
However, opencv2.framework directory is erased and recreated on each run.
"""

<<<<<<< HEAD
import glob, re, os, os.path, shutil, string, sys
=======
import glob, re, os, os.path, shutil, string, sys, exceptions, subprocess

def execute(cmd):
    try:
        print >>sys.stderr, "Executing:", cmd
        retcode = subprocess.call(cmd, shell=True)
        if retcode < 0:
            raise Exception("Child was terminated by signal:", -retcode)
        elif retcode > 0:
            raise Exception("Child returned:", retcode)
    except OSError as e:
        raise Exception("Execution failed:", e)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

def build_opencv(srcroot, buildroot, target, arch):
    "builds OpenCV for device or simulator"

    builddir = os.path.join(buildroot, target + '-' + arch)
    if not os.path.isdir(builddir):
        os.makedirs(builddir)
    currdir = os.getcwd()
    os.chdir(builddir)
    # for some reason, if you do not specify CMAKE_BUILD_TYPE, it puts libs to "RELEASE" rather than "Release"
    cmakeargs = ("-GXcode " +
                "-DCMAKE_BUILD_TYPE=Release " +
                "-DCMAKE_TOOLCHAIN_FILE=%s/platforms/ios/cmake/Toolchains/Toolchain-%s_Xcode.cmake " +
                "-DBUILD_opencv_world=ON " +
<<<<<<< HEAD
                "-DCMAKE_INSTALL_PREFIX=install") % (srcroot, target)
    # if cmake cache exists, just rerun cmake to update OpenCV.xproj if necessary
    if os.path.isfile(os.path.join(builddir, "CMakeCache.txt")):
        os.system("cmake %s ." % (cmakeargs,))
    else:
        os.system("cmake %s %s" % (cmakeargs, srcroot))
=======
                "-DCMAKE_C_FLAGS=\"-Wno-implicit-function-declaration\" " +
                "-DCMAKE_INSTALL_PREFIX=install") % (srcroot, target)

    if arch.startswith("armv"):
        cmakeargs += " -DENABLE_NEON=ON"

    # if cmake cache exists, just rerun cmake to update OpenCV.xcodeproj if necessary
    if os.path.isfile(os.path.join(builddir, "CMakeCache.txt")):
        execute("cmake %s ." % (cmakeargs,))
    else:
        execute("cmake %s %s" % (cmakeargs, srcroot))
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    for wlib in [builddir + "/modules/world/UninstalledProducts/libopencv_world.a",
                 builddir + "/lib/Release/libopencv_world.a"]:
        if os.path.isfile(wlib):
            os.remove(wlib)

<<<<<<< HEAD
    os.system("xcodebuild IPHONEOS_DEPLOYMENT_TARGET=6.0 -parallelizeTargets ARCHS=%s -jobs 8 -sdk %s -configuration Release -target ALL_BUILD" % (arch, target.lower()))
    os.system("xcodebuild IPHONEOS_DEPLOYMENT_TARGET=6.0 ARCHS=%s -sdk %s -configuration Release -target install install" % (arch, target.lower()))
=======
    execute("xcodebuild IPHONEOS_DEPLOYMENT_TARGET=6.0 -parallelizeTargets ARCHS=%s -jobs 8 -sdk %s -configuration Release -target ALL_BUILD" % (arch, target.lower()))
    execute("xcodebuild IPHONEOS_DEPLOYMENT_TARGET=6.0 ARCHS=%s -sdk %s -configuration Release -target install install" % (arch, target.lower()))
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    os.chdir(currdir)

def put_framework_together(srcroot, dstroot):
    "constructs the framework directory after all the targets are built"

    # find the list of targets (basically, ["iPhoneOS", "iPhoneSimulator"])
    targetlist = glob.glob(os.path.join(dstroot, "build", "*"))
    targetlist = [os.path.basename(t) for t in targetlist]

    # set the current dir to the dst root
    currdir = os.getcwd()
    framework_dir = dstroot + "/opencv2.framework"
    if os.path.isdir(framework_dir):
        shutil.rmtree(framework_dir)
    os.makedirs(framework_dir)
    os.chdir(framework_dir)

    # form the directory tree
    dstdir = "Versions/A"
    os.makedirs(dstdir + "/Resources")

    tdir0 = "../build/" + targetlist[0]
    # copy headers
    shutil.copytree(tdir0 + "/install/include/opencv2", dstdir + "/Headers")

    # make universal static lib
    wlist = " ".join(["../build/" + t + "/lib/Release/libopencv_world.a" for t in targetlist])
<<<<<<< HEAD
    os.system("lipo -create " + wlist + " -o " + dstdir + "/opencv2")
=======
    execute("lipo -create " + wlist + " -o " + dstdir + "/opencv2")
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    # copy Info.plist
    shutil.copyfile(tdir0 + "/ios/Info.plist", dstdir + "/Resources/Info.plist")

    # make symbolic links
    os.symlink("A", "Versions/Current")
    os.symlink("Versions/Current/Headers", "Headers")
    os.symlink("Versions/Current/Resources", "Resources")
    os.symlink("Versions/Current/opencv2", "opencv2")


def build_framework(srcroot, dstroot):
    "main function to do all the work"

<<<<<<< HEAD
    targets = ["iPhoneOS", "iPhoneOS", "iPhoneOS", "iPhoneSimulator", "iPhoneSimulator"]
    archs = ["armv7", "armv7s", "arm64", "i386", "x86_64"]
    for i in range(len(targets)):
        build_opencv(srcroot, os.path.join(dstroot, "build"), targets[i], archs[i])
=======
    targets = [("armv7", "iPhoneOS"),
               ("armv7s", "iPhoneOS"),
               ("arm64", "iPhoneOS"),
               ("i386", "iPhoneSimulator"),
               ("x86_64", "iPhoneSimulator")]
    for t in targets:
        build_opencv(srcroot, os.path.join(dstroot, "build"), t[1], t[0])
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    put_framework_together(srcroot, dstroot)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print "Usage:\n\t./build_framework.py <outputdir>\n\n"
        sys.exit(0)

<<<<<<< HEAD
    build_framework(os.path.abspath(os.path.join(os.path.dirname(sys.argv[0]), "../..")), os.path.abspath(sys.argv[1]))
=======
    try:
        build_framework(os.path.abspath(os.path.join(os.path.dirname(sys.argv[0]), "../..")), os.path.abspath(sys.argv[1]))
    except Exception as e:
        print >>sys.stderr, e
        sys.exit(1)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
