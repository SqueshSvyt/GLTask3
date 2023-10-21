cmake_minimum_required(VERSION 3.16)

project(MediaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS
    Quick
    Multimedia
    QuickControls2
    Gui
    REQUIRED)

qt_add_executable(appMediaPlayer
    main.cpp
)

qt_add_qml_module(appMediaPlayer
    URI MediaPlayer
    VERSION 1.0
    QML_FILES
    main.qml
    MenuBarPlayer.qml
    Imagebutton.qml
    Controlpanel.qml
    VideoPlayer.qml
    TimeSlider.qml
    LibraryZone.qml
    BaseButton.qml

    RESOURCES
    resources/images/play.png
    resources/images/pause.png
    resources/images/sound.png
    resources/images/mute.png
    resources/images/icon.ico
    resources/images/next.png
    resources/images/library.png
    resources/images/videochoose.png
    resources/images/add.png

    SOURCES
    mediaplayer.h
    mediaplayer.cpp
    audiooutput.h
    audiooutput.cpp
    filedriver.h
    filedriver.cpp
    library.h
    library.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMediaPlayer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMediaPlayer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMediaPlayer
    PRIVATE
    Qt6::Quick
    Qt6::Multimedia
    Qt6::QuickControls2
    Qt6::Gui
    )

include(GNUInstallDirs)
install(TARGETS appMediaPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
