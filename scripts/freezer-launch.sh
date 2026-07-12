#!/usr/bin/env bash

set -e

CONFIG="/usr/share/freezer/freezer-wireproxy.conf"

# Start wireproxy in background if not running
if ! pgrep -x wireproxy >/dev/null 2>&1; then
    wireproxy --config "$CONFIG" &
    WPID=$!
    # small delay to let it bind
    sleep 1
else
    WPID=""
fi

# Tell QtWebEngine/Chromium to use the SOCKS5 proxy
export QTWEBENGINE_CHROMIUM_FLAGS="--proxy-server=socks5://127.0.0.1:1080"

# Wayland first, X11 fallback
if [ -z "$WAYLAND_DISPLAY" ]; then
    export QT_QPA_PLATFORM=xcb
else
    export QT_QPA_PLATFORM=wayland
fi

freezer-bin

# Cleanup wireproxy if we started it
if [ -n "$WPID" ]; then
    kill "$WPID" 2>/dev/null || true
fi
