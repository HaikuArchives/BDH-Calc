NAME = bdhcalc
TYPE = APP
SRCS = src/bdh_main.cpp src/bdh_view.cpp
RSRCS = Ressources/bdh.rsrc
LIBS = be
APP_MIME_SIG = application/x-vnd.Hammond-BDH

include $(BUILDHOME)/etc/makefile-engine
