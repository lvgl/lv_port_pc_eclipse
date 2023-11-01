#
# Makefile
#
$(warning Using Make to build this project is deprecated, please switch to CMake)
CC ?= gcc
LVGL_DIR_NAME ?= lvgl
LVGL_DIR ?= ${shell pwd}

WARNINGS ?= -Wall -Werror=float-conversion -Wextra \
						-Wshadow -Wundef -Wmaybe-uninitialized -Wmissing-prototypes -Wno-discarded-qualifiers \
						-Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized \
						-Wno-unused-parameter -Wno-missing-field-initializers -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default  \
					  -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated  \
						-Wempty-body -Wshift-negative-value -Wstack-usage=2048 \
            -Wtype-limits -Wsizeof-pointer-memaccess -Wpointer-arith

CFLAGS ?= -O3 -I$(LVGL_DIR)/ $(WARNINGS) `pkg-config --cflags wayland-client` `pkg-config --cflags xkbcommon`
LDFLAGS ?= -lSDL2 -lm `pkg-config --libs wayland-client` `pkg-config --libs xkbcommon` -lpthread
BIN = demo

#Collect the files to compile
MAINSRC = ./main.c

include $(LVGL_DIR)/lvgl/lvgl.mk

CSRCS +=$(LVGL_DIR)/mouse_cursor_icon.c

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))
CXXOBJS = $(CXXSRCS:.cpp=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC) $(CXXSRCS)
OBJS = $(AOBJS) $(COBJS) $(CXXOBJS)

## MAINOBJ -> OBJFILES

all: default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"

%.o: %.cpp
	@$(CXX)  $(CFLAGS) -c $< -o $@
	@echo "CXX $<"

default: $(AOBJS) $(COBJS) $(MAINOBJ) $(CXXOBJS)
	$(CXX) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(CXXOBJS) $(LDFLAGS)

clean:
	rm -f $(BIN) $(AOBJS) $(COBJS) $(CXXOBJS) $(MAINOBJ)

