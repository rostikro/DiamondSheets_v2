
antlr_target(DiamondSheetsGrammar ../grammar/DiamondSheets.g4 VISITOR OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/grammar)

# Added this definition because of conflict between qt keywords and antlr lib
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

add_executable(DiamondSheets WIN32 main.cpp
        DiamondSheets.cpp
        DiamondSheets.h
        TableModel.cpp
        TableModel.h
        Cell.cpp
        Cell.h
        Utils.h
        ParserResult.h
        ExpressionParser.cpp
        ExpressionParser.h
        ${ANTLR_DiamondSheetsGrammar_CXX_OUTPUTS}
        FileManager.cpp
        FileManager.h
        GoogleApi.cpp
        GoogleApi.h
        GoogleDriveApi.cpp
        GoogleDriveApi.h
)

target_link_libraries(DiamondSheets
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        Qt::NetworkAuth
)
target_link_libraries(DiamondSheets antlr4_shared)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    add_custom_command(TARGET DiamondSheets
            POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            -E copy ${ANTLR4_RUNTIME_LIBRARIES} .
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/tls/")
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/tls/qopensslbackend${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/tls/qopensslbackend${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/tls/")
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/tls/qschannelbackend${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/tls/qschannelbackend${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/tls/")
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/tls/qcertonlybackend${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/tls/qcertonlybackend${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/tls/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Network NetworkAuth)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()