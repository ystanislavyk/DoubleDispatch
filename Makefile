#% USAGE: Project building via Terminal/Linux console
#%
#% NOTE: GCC and debug mode is used by default

#% TARGETS:
#%
#%  $ make clean
#%  $ make all
#%  $ make gcc-debug
#%  $ make gcc-release
#%  $ make clang-debug
#%  $ make clang-release

.DEFAULT_GOAL=gcc-debug

### Constants
BUILD_DIR := build

########################################################################################################################

clean:
	rm -rf $(BUILD_DIR)

all:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && ../scripts/build_project.sh gcc Debug
	cd $(BUILD_DIR) && ../scripts/build_project.sh gcc Release
	cd $(BUILD_DIR) && ../scripts/build_project.sh clang Debug
	cd $(BUILD_DIR) && ../scripts/build_project.sh clang Release

gcc-debug:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && ../scripts/build_project.sh gcc Debug

gcc-release:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && ../scripts/build_project.sh gcc Release

clang-debug:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && ../scripts/build_project.sh clang Debug

clang-release:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && ../scripts/build_project.sh clang Release
