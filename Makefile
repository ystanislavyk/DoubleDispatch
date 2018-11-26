CLANG_DEBUG_BUILD_DIR = build-clang-debug
CLANG_RELEASE_BUILD_DIR = build-clang-release

GCC_DEBUG_BUILD_DIR = build-gcc-debug
GCC_RELEASE_BUILD_DIR = build-gcc-release


default:clang-debug

clang-debug:
	mkdir $(CLANG_DEBUG_BUILD_DIR)
	cd $(CLANG_DEBUG_BUILD_DIR) && CXX=clang++ cmake .. && make -j$(nproc)

clang-release:
	mkdir $(CLANG_RELEASE_BUILD_DIR)
	cd $(CLANG_RELEASE_BUILD_DIR) && CXX=clang++ cmake .. -DCMAKE_BUILD_TYPE=Release && make -j$(nproc)

gcc-debug:
	mkdir $(GCC_DEBUG_BUILD_DIR)
	cd $(GCC_DEBUG_BUILD_DIR) && CXX=g++ cmake .. && make -j$(nproc)

gcc-release:
	mkdir $(GCC_RELEASE_BUILD_DIR)
	cd $(GCC_RELEASE_BUILD_DIR) && CXX=g++ cmake .. -DCMAKE_BUILD_TYPE=Release && make -j$(nproc)

clean:
	rm -rf $(CLANG_DEBUG_BUILD_DIR)
	rm -rf $(CLANG_RELEASE_BUILD_DIR)
	rm -rf $(GCC_DEBUG_BUILD_DIR)
	rm -rf $(GCC_RELEASE_BUILD_DIR)
