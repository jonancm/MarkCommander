cmake_minimum_required (VERSION 2.6)

# Find Qt 4
find_package (Qt4 REQUIRED QtCore QtGui)

# Fetch QextSerialPort from the Bitbucket repository
include (ExternalProject)
ExternalProject_Add (qextserialport
                     GIT_REPOSITORY https://Genba@bitbucket.org/Genba/qextserialport.git
                     GIT_TAG 3be3fbf31edf6c91c7838f585b77acd787811296
                     CONFIGURE_COMMAND "qmake"
                     INSTALL_COMMAND ""
                     BUILD_IN_SOURCE 1)
