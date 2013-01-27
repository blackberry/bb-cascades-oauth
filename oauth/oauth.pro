TEMPLATE = lib
TARGET = kqoauth
CONFIG += dll qt warn_on debug_and_release cascades
SOURCES += *.cpp
HEADERS += *.hpp *.h
QT += network
DEFINES += KQOAUTH

device {
	CONFIG(release, debug|release) {
		DESTDIR = o.le-v7
	}
	CONFIG(debug, debug|release) {
		DESTDIR = o.le-v7-g
	}
}

simulator {
	CONFIG(release, debug|release) {
		DESTDIR = o
	}
	CONFIG(debug, debug|release) {
		DESTDIR = o-g
	}
}

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.moc
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR = $${DESTDIR}/.ui

suredelete.target = sureclean
suredelete.commands = $(DEL_FILE) $${MOC_DIR}/*
suredelete.depends = distclean

QMAKE_EXTRA_TARGETS += suredelete
