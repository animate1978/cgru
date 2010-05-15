#!/bin/bash

# Setup Afanasy:
source ./setup_afanasy.sh

# directory where Houdini installed (default value):
export HOUDINI_LOCATION=/cg/soft/houdini-10

# overrides (set custom values there):
[ -f override.sh ] && source override.sh

pwd=$PWD
cd $HOUDINI_LOCATION
source houdini_setup_bash
cd $pwd

# Set Afanasy houdini scripts version
export HOUDINI_AF_VERSION="10"
# Set Afanasy houdini scripts location
export HOUDINI_AF_PATH=$AF_ROOT/plugins/houdini/houdini$HOUDINI_AF_VERSION

export HOUDINI_AF_OTLSCAN_PATH=$HIH/otls:$HOUDINI_AF_PATH/otls:$HH/otls

if [ "$HOUDINI_OTLSCAN_PATH" != "" ]; then
   export HOUDINI_OTLSCAN_PATH="${HOUDINI_AF_OTLSCAN_PATH}:${HOUDINI_OTLSCAN_PATH}"
else
   export HOUDINI_OTLSCAN_PATH=$HOUDINI_AF_OTLSCAN_PATH
fi
