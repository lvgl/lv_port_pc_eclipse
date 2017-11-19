################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include misc/templ/subdir.mk
-include misc/others/subdir.mk
-include misc/os/subdir.mk
-include misc/mem/subdir.mk
-include misc/math/subdir.mk
-include misc/gfx/fonts/subdir.mk
-include misc/gfx/subdir.mk
-include misc/fs/ufs/subdir.mk
-include misc/fs/linuxfs/subdir.mk
-include misc/fs/fat32/option/subdir.mk
-include misc/fs/fat32/subdir.mk
-include misc/fs/subdir.mk
-include misc/subdir.mk
-include lvgl/lv_themes/subdir.mk
-include lvgl/lv_objx/subdir.mk
-include lvgl/lv_obj/subdir.mk
-include lvgl/lv_hal/subdir.mk
-include lvgl/lv_draw/subdir.mk
-include lv_examples/lv_tutorial/9_keyboard_ctrl/subdir.mk
-include lv_examples/lv_tutorial/8_encoder_ctrl/subdir.mk
-include lv_examples/lv_tutorial/7_button_ctrl/subdir.mk
-include lv_examples/lv_tutorial/6_anti_aliasing/subdir.mk
-include lv_examples/lv_tutorial/5_animations/subdir.mk
-include lv_examples/lv_tutorial/4_responsive/subdir.mk
-include lv_examples/lv_tutorial/3_styles/subdir.mk
-include lv_examples/lv_tutorial/2_objects/subdir.mk
-include lv_examples/lv_tutorial/1_hello_world/subdir.mk
-include lv_examples/lv_tutorial/10_mouse_ctrl/subdir.mk
-include lv_examples/lv_tests/lv_test_theme/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_win/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_tabview/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_ta/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_sw/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_slider/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_roller/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_page/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_mbox/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_lmeter/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_list/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_line/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_led/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_label/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_kb/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_img/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_gauge/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_ddlist/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_cont/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_chart/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_cb/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_btnm/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_btn/subdir.mk
-include lv_examples/lv_tests/lv_test_objx/lv_test_bar/subdir.mk
-include lv_examples/lv_tests/lv_test_obj/subdir.mk
-include lv_examples/lv_tests/lv_test_group/subdir.mk
-include lv_examples/lv_apps/subdir.mk
-include lv_dev_tools/demo/subdir.mk
-include hw/per/psp/pic32mz/subdir.mk
-include hw/per/psp/pic32mx/subdir.mk
-include hw/per/psp/pic24f_33f/subdir.mk
-include hw/per/psp/pc/subdir.mk
-include hw/per/psp/kea/subdir.mk
-include hw/per/subdir.mk
-include hw/dev/wifi/subdir.mk
-include hw/dev/ui/subdir.mk
-include hw/dev/tp/subdir.mk
-include hw/dev/sens/subdir.mk
-include hw/dev/io_exp/subdir.mk
-include hw/dev/gsm/subdir.mk
-include hw/dev/ext_mem/subdir.mk
-include hw/dev/dispc/subdir.mk
-include hw/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lv_dev_5

# Tool invocations
lv_dev_5: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	gcc  -o "lv_dev_5" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) lv_dev_5
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
