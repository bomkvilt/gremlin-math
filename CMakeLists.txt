if  (${bDouble})
    set(math_precission "bDouble")
else()
    set(math_precission "bFloat")
    endif()

GN_Unit(math
    units reflect
    defs_public ${math_precission}
)
