TEMPLATE = lib
TARGET = qleapGesture
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = Leap
userapp = QLeapGestureTest
# set your LeapSDK path
# leap_sdk_path = C:/Path/To/Your/LeapSDK
leap_sdk_path = C:/Users/Murakami/LeapDeveloperKit/LeapSDK
INCLUDEPATH += $${leap_sdk_path}/include
win32:LIBS += $${leap_sdk_path}/lib/x86/Leap.lib
win32 {
    CONFIG(debug,debug|release) {
      DESTDIR = ../$${userapp}/debug/$$replace(uri, \\., /)
    } else {
      DESTDIR = ../$${userapp}/release/$$replace(uri, \\., /)
    }
}
# Input
SOURCES += \
    qleapgesture_plugin.cpp \
    qleapgesture.cpp \
    qleapeventlistener.cpp

HEADERS += \
    qleapgesture_plugin.h \
    qleapgesture.h \
    qleapeventlistener.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/$$DESTDIR/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

