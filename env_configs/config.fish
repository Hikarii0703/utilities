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

