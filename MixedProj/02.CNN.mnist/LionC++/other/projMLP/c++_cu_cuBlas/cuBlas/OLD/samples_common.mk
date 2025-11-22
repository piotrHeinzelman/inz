#Setting SMS for all samples
#architecture

CUDA_VERSION := $(shell cat $(CUDA_PATH)/include/cuda.h |grep "define CUDA_VERSION" |awk '{print $$3}')
$(info CUDA_VERSION is ${CUDA_VERSION})
#Link against cublasLt for CUDA 10.1 and up.
CUBLASLT:=false
ifeq ($(shell test $(CUDA_VERSION) -ge 10010; echo $$?),0)
CUBLASLT:=true
endif
$(info Linking agains cublasLt = $(CUBLASLT))

SMS_VOLTA = 75

SMS_AMPERE =
ifeq ($(shell expr $(CUDA_VERSION) \>= 11000),1)
SMS_AMPERE = 80
endif

ifeq ($(shell expr $(CUDA_VERSION) \>= 11010),1)
SMS_AMPERE += 86
endif

ifeq ($(shell expr $(CUDA_VERSION) \>= 11042),1)
SMS_AMPERE += 87
endif

SMS_HOPPER =
ifeq ($(shell expr $(CUDA_VERSION) \>= 11080),1)
SMS_HOPPER += 90
endif

SMS_BLACKWELL =
ifeq ($(shell expr $(CUDA_VERSION) \>= 13000),1)
SMS_BLACKWELL += 100 110 120
else ifeq ($(shell expr $(CUDA_VERSION) \>= 12080),1)
SMS_BLACKWELL += 100 101 120
endif

SMS ?= $(SMS_VOLTA) $(SMS_AMPERE) $(SMS_HOPPER) $(SMS_BLACKWELL)
