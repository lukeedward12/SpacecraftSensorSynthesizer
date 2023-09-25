set(SOURCES_functional
S3_functional_test.cpp
${SOURCE_DIR}/sensor_synthesizer/sensor_synthesizer.cpp
${SOURCE_DIR}/logger/logger.cpp
)
add_executable(S3_functional ${SOURCES_functional})
add_test(NAME S3_functional COMMAND S3_functional) 
target_include_directories(S3_functional PRIVATE ${SOURCE_DIR}/sensor_synthesizer)
target_include_directories(S3_functional PRIVATE ${SOURCE_DIR}/logger)
target_include_directories(S3_functional PRIVATE ${SOURCE_DIR}/networking)