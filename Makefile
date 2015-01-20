all: bpb.so
bpb.so: bpb_api.h intern/*.cxx intern/*.h
	panc++ -shared -o bpb.so -O1 -ggdb -fPIC intern/bpb_composite.cxx -I. -I/home/rdb/local/src/blender/source/blender/makesdna/
clean:
	rm -f bpb.so
.PHONY: all clean
