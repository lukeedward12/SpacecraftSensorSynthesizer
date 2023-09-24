set(SOURCES
    main.cpp
    sensor_synthesizer/sensor_synthesizer.cpp
    logger/logger.cpp
    # Add more source files here
)

add_executable(target ${SOURCES}) # specify the executable to be built and its source files
target_include_directories(target PUBLIC sensor_synthesizer)
target_include_directories(target PUBLIC logger)
target_include_directories(target PUBLIC networking)