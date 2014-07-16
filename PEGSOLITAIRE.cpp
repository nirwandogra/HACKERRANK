include ../lib/config.mk

#CC += -faddress-sanitizer -fno-omit-frame-pointer
LDFLAGS := -L"../lib" -lccv $(LDFLAGS)
CFLAGS := -O3 -Wall -I"../lib" $(CFLAGS)

TARGETS = bbffmt msermatch siftmatch bbfcreate bbfdetect swtcreate swtdetect dpmcreate dpmdetect convert tld icfcreate icfdetect icfoptimize cifar-10 image-net cnnclassify

all: libccv.a $(TARGETS)

clean:
	${MAKE} clean -C ../lib ; rm -f *.o $(TARGETS)

$(TARGETS): %: %.o libccv.a
	$(CC) -o $@ $< $(LDFLAGS)

libccv.a:
	${MAKE} -C ../lib

%.o: %.c ../lib/ccv.h
	$(CC) $< -o $@ -c $(CFLAGS)
