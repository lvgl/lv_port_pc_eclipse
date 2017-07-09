# Hardware Abstraction Layer (HAL) for Littlev Graphics Library

This repository contains and example Hardware Abstraction Layer (HAL) for Littlev Graphics Library. The graphics library uses the functions in these files to access to your:
* Display
* Touch pad
* System tick

In the HAL you have to write only **5 simple functions**.

## Display drivers (hal/disp)
To access to the display 2 functions are used:

`disp_fill(x1, y1, x2, y2, color)`Fill a rectangular area with a color

`disp_map(x1, y1, x2, y2, color_array)`Copy an array of colors to a rectangular area

## Input device (hal/indev)
You can use multiple input devices for example a touch pad and some buttons which are pressing specific points on the display

`indev_get(id, *x, *y)` Read the *x* and *y* coordinates from an input device. Return *false* if the input device released, *true* is pressed.

In *indev.h* you have to define **INDEV_NUM** according to the number of input devices. For example if you are using only a touch pad: `#define INDEV_NUM  1`

## System tick (hal/systick)
You have to provide possibility to get a system tick counter with 1 ms resolution.

`systick_get()` Get the elapsed milliseconds since start up

The `systick_elaps(prev_time)` function is also required but is already have been written.

The `systick_add_cb(func)` and `systick_rem_cb(func)` are optional and are required only fro some specific components from the [Misc. Library] (https://github.com/littlevgl/misc)
