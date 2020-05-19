
add_definitions(-DAPPLICATIONCLIENTCORE_LIBRARY)
add_definitions(-D_QX_ENABLE_QT_NETWORK)
file(GLOB SRCl
    "*.cpp"
)
file(GLOB HEADERl
    "*.h"
    "*.hpp"
)
file(GLOB UISl
    "*.ui"
)
file(GLOB RSC1
    "*.qrc"
)
set(SRC ${SRC} ${SRCl} PARENT_SCOPE)
set(HEADER ${HEADER} ${HEADERl} PARENT_SCOPE)
set(UIS ${UIS} ${UISl} PARENT_SCOPE)
set(RSC ${RSC} ${RSC1} PARENT_SCOPE)