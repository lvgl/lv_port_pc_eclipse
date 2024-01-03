# Eclipse Simulator for LVGL (using SDL)

The [LVGL](https://github.com/lvgl/lvgl) is written mainly for microcontrollers and embedded systems however you can run the library **on your PC** as well without any embedded hardware. The code written on PC can be simply copied when your are using an embedded system.

The PC simulator is cross platform.  **Windows, Linux and OSX** are supported, however on Windows it's easier to get started with a [another simulator](https://docs.lvgl.io/latest/en/html/get-started/pc-simulator.html) project.

This project uses [Eclipse CDT](https://projects.eclipse.org/projects/tools.cdt) (as an IDE) and [SDL](https://www.libsdl.org/) =a low level driver library to open a window, and handle mouse, keyboard etc.)

## Get started

### Install Packages

On Linux you can easiyl install it the requirements via terminal:
```
sudo apt-get update && sudo apt-get install -y build-essential libsdl2-dev libsdl2-image-dev libjpeg-dev libpng-dev
```

Or you can download SDL from [https://www.libsdl.org/](https://www.libsdl.org/).


### Get this project

Clone this repository and the related submodules to the workspace folder of Eclipse:

```
git clone --recursive https://github.com/lvgl/lv_port_pc_eclipse
```

### Import the PC simulator project
1. Open Eclipse CDT
2. Click **File->Import** and choose **General->Existing project into Workspace**
3. Browse the root directory of the project and click Finish
4. Build your project and run it

This configures in this project, but if you start a new Eclipse project due to an Eclipse bug you need modify the Assembler command:
1. In Project properties -> C/C++ build -> Settings -> Cross GCC Assembler -> Command: change `as` to `gcc`
2. On the same place: Cross GCC Assembler -> General -> Assembler flags: add `-c` 

## CMake

The following steps can be used with CMake on a Unix-like system. This may also work on other OSes but has not been tested.

1. Ensure CMake is installed, i.e. the `cmake` command works on the terminal.
2. Make a new directory. The name doesn't matter but `build` will be used for this tutorial.
3. Type `cd build`.
4. Type `cmake ..`. CMake will generate the appropriate build files.
   - To build with SDL draw unit, add `-DLV_USE_DRAW_SDL=ON` to command line
   - To build with libpng to support PNG image, add `-DLV_USE_LIBPNG=ON` to command line
   - To build with libjpeg-turbo to support JPEG image, add `-DLV_USE_LIBJPEG_TURBO=ON` to command line
5. Type `make -j` or (more portable) `cmake --build . --parallel`.

**NOTE:** `--parallel` is supported from CMake v3.12 onwards. If you are using an older version of CMake, remove `--parallel` from the command or use the make option.

6. The binary will be in `../bin/main`, and can be run by typing that command.

## Docker
1. Build the docker container
```
docker build -t lvgl_simulator .
```
2. Run the docker container
```
docker run lvgl_simulator
```
GUI with docker is platform dependent. For example, on macOS you can follow
[this tutorial](https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc)
and run a command similar to:
```
docker run -e DISPLAY=10.103.56.101:0 lvgl_simulator
```

Note that on macOS, you may need to enable indirect GLX rendering before starting Xquartz:
```
defaults write org.macosforge.xquartz.X11 enable_iglx -bool true
open -a Xquartz
```

For Linux environments with X Server, the following will the `docker run` command. Note that the first command, `xhost +` grants access to X server to everyone.

```
xhost +
docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix:ro -t lvgl_simulator
```
## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request!

If you find an issue, please report it on GitHub!
