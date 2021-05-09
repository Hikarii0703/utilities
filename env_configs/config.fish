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
alias v "NVIM_LISTEN_ADDRESS=/tmp/nvimsocket nvim"
alias gv "NVIM_LISTEN_ADDRESS=/tmp/nvimsocket nvim-gtk"
alias p "download_prob.py samples"
alias t "cf test"
alias e "nvr -s"
alias bat batcat
alias ff "fzf --preview 'bat --color=always --style=numbers --theme=ansi-dark --line-range=:500 {}'"

function fish_user_key_bindings
    for mode in insert default visual
        bind -M $mode \cf forward-char
    end
end

function pt
    tmux new-session \; split-window -h \; select-pane -L
end

function setenv; set -gx $argv; end
source ~/.env

fish_default_key_bindings
set -U fish_greeting
