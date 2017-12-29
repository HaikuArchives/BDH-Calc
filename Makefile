NAME = bdhcalc
TYPE = APP
SRCS = \
	 src/bdh_main.cpp	\
	 src/bdh_view.cpp	\

RSRCS = Ressources/bdh.rsrc
LIBS = be $(STDCPPLIBS)
APP_MIME_SIG = application/x-vnd.Hammond-BDH

## Include the Makefile-Engine
DEVEL_DIRECTORY := \
	$(shell findpaths -r "makefile_engine" B_FIND_PATH_DEVELOP_DIRECTORY)
include $(DEVEL_DIRECTORY)/etc/makefile-engine