QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    meddialog.cpp \
    search.cpp \
    timthuoc.cpp \
    updatemed.cpp

HEADERS += \
    mainwindow.h \
    meddialog.h \
    search.h \
    timthuoc.h \
    updatemed.h

FORMS += \
    mainwindow.ui \
    meddialog.ui \
    search.ui \
    timthuoc.ui \
    updatemed.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinKH/0834070422.csv \
    ../build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinKH/0834070422.csv \
    ../build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinKH/0834070422.csv \
    ../build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinKH/0834070422.csv \
    ../build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinKH/0834070422.txt \
    ../build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinthuoc/thongtinthuoc.csv \
    E:/Semester_2nd_Yeard_3rd/Code_Data_Structure/build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinKH/madonthuoc.txt \
    E:/Semester_2nd_Yeard_3rd/Code_Data_Structure/build-begin-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/thongtinthuoc/thongtinthuoc.csv \
    E:/Semester_2nd_Yeard_3rd/Data_Structure/thongtinKH/madonthuoc.txt \
    E:/Semester_2nd_Yeard_3rd/Data_Structure/thongtinkh/thongtinkh.csv \
    E:/Semester_2nd_Yeard_3rd/Data_Structure/thongtinthuoc/BN01.csv \
    E:/Semester_2nd_Yeard_3rd/Data_Structure/thongtinthuoc/thongtinthuoc.csv \
    thongtinKH/madonthuoc.txt \
    thongtinKH/madonthuoc.txt \
    thongtinthuoc/thongtinthuoc.csv

RESOURCES += \
    Icon.qrc

RC_FILE = begin.rc
