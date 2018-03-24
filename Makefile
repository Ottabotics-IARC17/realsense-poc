CXX := g++ -g -Wall --std=c++11
OCVFLAGS := `pkg-config --cflags --libs opencv`
RSFLAGS := -Iinclude -L/usr/local/lib -lrealsense

.PHONY: example1
example1:
	$(CXX) example1.cpp $(RSFLAGS) -o bin/example1

.PHONY: example2
example2:
	$(CXX) example2.cpp $(RSFLAGS) -o bin/example2

.PHONY: example3
example3:
	$(CXX) example3.cpp $(RSFLAGS) -I/usr/include -L/usr/lib/x86_64-linux-gnu -lglfw -o bin/example3

.PHONY: examples
examples: example1

.PHONY: opencv-rs-1
opencv-rs-1:
	$(CXX) opencv-rs-1.cpp $(RSFLAGS) $(OCVFLAGS) -o bin/opencv-rs-1

.PHONY: opencv-rs-ir-1
opencv-rs-ir-1:
	$(CXX) opencv-rs-ir-1.cpp $(RSFLAGS) $(OCVFLAGS) -o bin/opencv-rs-ir-1

.PHONY: opencv-rs-ir-2
opencv-rs-ir-2:
	$(CXX) opencv-rs-ir-2.cpp $(RSFLAGS) $(OCVFLAGS) -o bin/opencv-rs-ir-2
