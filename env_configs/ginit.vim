if exists('g:GtkGuiLoaded')
    call rpcnotify(1, 'Gui', 'Font', 'JetBrains Mono 10')
    call rpcnotify(1, 'Gui', 'Option', 'Popupmenu', 0)
    call rpcnotify(1, 'Gui', 'Option', 'Tabline', 0)
    call rpcnotify(1, 'Gui', 'Command', 'SetCursorBlink', '0')
endif
