set(srcs
    "ds1307.c")

set(includes 
    ".")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS ${includes})
