set PATH $PATH ~/spicetify-cli
set PATH $PATH ~/.cargo/bin
set PATH $PATH ~/.local/bin
set PATH $PATH ~/.poetry/bin

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

<<<<<<< HEAD
function fish_user_key_bindings
    for mode in insert default visual
        bind -M $mode \cf forward-char
    end
end

function quick_git_push
    git add .
    git commit -am.
    git push origin master
end
=======
>>>>>>> 87e0a4be08532da571d26846fd53fcacc5fbcdbb
