set(plugin_SRCS
    plugin.cpp
    screenshotgrabber.cpp
)

install(FILES qmldir DESTINATION ${QML_INSTALL_DIR}/org/kde/mobile/private/screenshot)

add_library(screenshotplugin SHARED ${plugin_SRCS})

target_link_libraries(screenshotplugin
    Qt5::Core
    Qt5::Qml
    Qt5::Quick
    Qt5::DBus
)

install(TARGETS screenshotplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/mobile/private/screenshot)
