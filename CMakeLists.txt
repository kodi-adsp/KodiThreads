project(KodiThreads)

set(SOURCES KodiThreads/threads/Atomics.cpp
            KodiThreads/threads/Event.cpp
            KodiThreads/threads/Thread.cpp
            KodiThreads/threads/Timer.cpp
            KodiThreads/threads/SystemClock.cpp
            KodiThreads/commons/Exception.cpp
            KodiThreads/system.cpp)

set(HEADERS KodiThreads/threads/platform/Implementation.cpp

            KodiThreads/threads/Atomics.h
            KodiThreads/threads/Condition.h
            KodiThreads/threads/CriticalSection.h
            KodiThreads/threads/Event.h
            KodiThreads/threads/Helpers.h
            KodiThreads/threads/Lockables.h
            KodiThreads/threads/MipsAtomics.h
            KodiThreads/threads/SharedSection.h
            KodiThreads/threads/SingleLock.h
            KodiThreads/threads/SystemClock.h
            KodiThreads/threads/Thread.h
            KodiThreads/threads/ThreadImpl.h
            KodiThreads/threads/ThreadLocal.h
            KodiThreads/threads/Timer.h
            KodiThreads/threads/platform/Condition.h
            KodiThreads/threads/platform/CriticalSection.h
            KodiThreads/threads/platform/ThreadImpl.h
            KodiThreads/threads/platform/ThreadLocal.h

            KodiThreads/system.h
            KodiThreads/commons/Exception.h)

include_directories(${p8-platform_INCLUDE_DIRS})
            
if(MSVC)
  list(APPEND SOURCES KodiThreads/threads/platform/win/Win32Exception.cpp)
  list(APPEND HEADERS KodiThreads/threads/platform/win/Win32Exception.h)
endif()

addon_source_group("${SOURCES}")
addon_source_group("${HEADERS}")

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
add_library(kodi::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/KodiThreads
                           INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/KodiThreads>
                                     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
if(MSVC)
  target_link_libraries(${PROJECT_NAME} PUBLIC winmm.lib)
endif()

# install all specific module files
install(TARGETS ${PROJECT_NAME} EXPORT kodi DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
