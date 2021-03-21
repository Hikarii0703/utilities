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
alias vim "nvim"
alias gvim "nvim-gtk"

function fish_user_key_bindings
    for mode in insert default visual
        bind -M $mode \cf forward-char
    end
end

function getin
    download_prob.py samples
end

function ptmux
    tmux new-session \; split-window -h \; select-pane -L
end

function setenv; set -gx $argv; end
source ~/.env

fish_vi_key_bindings
set -U fish_greeting
