set PATH $PATH ~/spicetify-cli
set PATH $PATH ~/.cargo/bin
set PATH $PATH ~/.local/bin
set PATH $PATH ~/.poetry/bin
set PATH $PATH ~/.npm-packages/bin
set PATH $PATH /usr/local/go/bin
set NPM_PACKAGES "$HOME/.npm-packages"
set PATH $PATH $NPM_PACKAGES/bin
set MANPATH $NPM_PACKAGES/share/man $MANPATH  

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

function quick_git_push
    git add .
    git commit -am.
    git push origin master
end

function getin
    download_prob.py samples
end

