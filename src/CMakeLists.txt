if (ESP_PLATFORM AND DEFINED ENV{IDF_PATH})
    idf_component_register(INCLUDE_DIRS ".")
endif()
