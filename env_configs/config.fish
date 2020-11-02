set PATH $PATH ~/spicetify-cli
set PATH $PATH ~/.cargo/bin
set PATH $PATH ~/.local/bin

function fm
    set tmpfile "/tmp/pwd-from-ranger"
    ranger --choosedir=$tmpfile $argv
    set rangerpwd (cat $tmpfile)
    if test "$PWD" != $rangerpwd
        cd $rangerpwd
    end
end

function mkcdir
    mkdir -p -- "$argv"
    cd "$argv"
end

alias l "ls -l -a"

function fish_user_key_bindings
    for mode in insert default visual
        bind -M $mode \cf forward-char
    end
end
