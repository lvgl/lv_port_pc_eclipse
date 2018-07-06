#
# Makefile
#
CC ?= gcc
CFLAGS += -Wall -Wshadow -Wundef -Wmaybe-uninitialized
CFLAGS += -I./
LDFLAGS += -lm

# Assume the user wants to build a SDL2-simulated demo. If building for
# a real board or not using SDL, then set LVGL_USE_SDL=0 in your build.
LVGL_USE_SDL ?= 1
ifeq "$(LVGL_USE_SDL)" "1"
# The CFLAGS to build a SDL2-based app.
CFLAGS += -DUSE_MONITOR=1 -DUSE_MOUSE=1 -DUSE_KEYBOARD=1
# Add libSDL2 to linker flags
LDFLAGS += -lSDL2
endif				# if LVGL_USE_SDL

# Allow debug and release builds via the DEBUG var. Release is default.
ifeq "$(DEBUG)" "1"
CFLAGS += -DDEBUG=1
CFLAGS += -O0 -g3
else
CFLAGS += -O3 -DNDEBUG
endif

BIN = demo
VPATH =

LVGL_DIR ?= ${shell pwd}

MAINSRC = main.c

#LIBRARIES
include ./lvgl/lv_core/lv_core.mk
include ./lvgl/lv_hal/lv_hal.mk
include ./lvgl/lv_objx/lv_objx.mk
include ./lvgl/lv_misc/lv_fonts/lv_fonts.mk
include ./lvgl/lv_misc/lv_misc.mk
include ./lvgl/lv_themes/lv_themes.mk
include ./lvgl/lv_draw/lv_draw.mk

#DRIVERS
include ./lv_drivers/display/display.mk
include ./lv_drivers/indev/indev.mk

ifneq "$(LVGL_MINIMAL_BUILD)" "1"

#EXAMPLES
include ./lv_examples/lv_tests/lv_test_obj/lv_test_obj.mk
include ./lv_examples/lv_tests/lv_test_stress/lv_test_stress.mk
include ./lv_examples/lv_tests/lv_test_theme/lv_test_theme.mk
include ./lv_examples/lv_tests/lv_test_group/lv_test_group.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_bar/lv_test_bar.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_btn/lv_test_btn.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_btnm/lv_test_btnm.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_cb/lv_test_cb.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_chart/lv_test_chart.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_cont/lv_test_cont.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_ddlist/lv_test_ddlist.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_gauge/lv_test_gauge.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_img/lv_test_img.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_kb/lv_test_kb.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_label/lv_test_label.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_led/lv_test_led.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_line/lv_test_line.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_list/lv_test_list.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_lmeter/lv_test_lmeter.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_mbox/lv_test_mbox.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_page/lv_test_page.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_roller/lv_test_roller.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_slider/lv_test_slider.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_sw/lv_test_sw.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_ta/lv_test_ta.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_tabview/lv_test_tabview.mk
include ./lv_examples/lv_tests/lv_test_objx/lv_test_win/lv_test_win.mk

include ./lv_examples/lv_apps/benchmark/benchmark.mk
include ./lv_examples/lv_apps/demo/demo.mk
include ./lv_examples/lv_apps/sysmon/sysmon.mk
include ./lv_examples/lv_apps/terminal/terminal.mk
include ./lv_examples/lv_apps/tpcal/tpcal.mk

include ./lv_examples/lv_tutorial/1_hello_world/lv_tutorial_hello_world.mk
include ./lv_examples/lv_tutorial/2_objects/lv_tutorial_objects.mk
include ./lv_examples/lv_tutorial/3_styles/lv_tutorial_styles.mk
include ./lv_examples/lv_tutorial/4_themes/lv_tutorial_themes.mk
include ./lv_examples/lv_tutorial/5_antialiasing/lv_tutorial_antialiasing.mk
include ./lv_examples/lv_tutorial/6_images/lv_tutorial_images.mk
include ./lv_examples/lv_tutorial/7_fonts/lv_tutorial_fonts.mk
include ./lv_examples/lv_tutorial/8_animations/lv_tutorial_animations.mk
include ./lv_examples/lv_tutorial/9_responsive/lv_tutorial_responsive.mk
include ./lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.mk

else

# You will need to change this include if building a different example!
include ./lv_examples/lv_apps/demo/demo.mk

endif	# LVGL_MINIMAL_BUILD

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS)

## MAINOBJ -> OBJFILES

all: default

%.o: %.c
	@echo "CC $<"
ifeq "$(DEBUG)" "1"
	$(CC)  $(CFLAGS) -c $< -o $@
else
	@$(CC)  $(CFLAGS) -c $< -o $@
endif

default: $(AOBJS) $(COBJS) $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(LDFLAGS)

clean:
	rm -f $(AOBJS) $(COBJS) $(MAINOBJ)

maintainer-clean:
	rm -f $(BIN) $(AOBJS) $(COBJS) $(MAINOBJ)

help:
	@cat ./BUILDING
