set(srcs
    "ds1307.c")

set(includes 
    ".")

set(requires mcu_port)

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS ${includes}
                       REQUIRES ${requires})
