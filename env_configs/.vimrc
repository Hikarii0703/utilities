"========== Plugins =========="
call plug#begin('~/.vim/plugged')

Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdcommenter'
Plug 'SirVer/ultisnips'
Plug 'rakr/vim-one'
Plug 'cohama/lexima.vim'
Plug 'lifepillar/vim-solarized8'

call plug#end()
"========== Colorcheme =========="
syntax enable
set termguicolors background=light
colorscheme solarized8
let g:lightline = {'colorscheme': 'solarized'}
"========== Settings =========="
" indentation
filetype plugin indent on
set shiftwidth=4 tabstop=4 expandtab softtabstop=4 cinoptions+=L0
set autoindent smartindent cindent

" misc vim config
set laststatus=2
set noshowmode
set number
set encoding=utf-8
set showcmd

" switch between absolute and relative number
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

" don't clear clipboard on exit
set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

" no backups
set nobackup noswapfile

" nerd commenter
let g:NERDSpaceDelims = 1
map <C-c> <leader>cb
map <C-x> <leader>cu

" ultisnips + autocomplete
map <leader>y <C-y>

" autoformat with astyle
map <leader>fm :%!astyle --mode=c --style=google -xV -H -y -j -xf<CR>
"========== CP config =========="
set shell=/usr/bin/zsh\ -i
map <F2> :w <bar> !CFCheck "%:t"<CR>
map <F3> :%y+<CR>
map <F5> :w <bar> !CFSubmit "%:t"<CR>
map <F9> :w <bar> !contest "%:t"<CR>
map <F10> :!run_contest "%:t"<CR>
map <F8> :!run_contest "%:t" in<CR>

" add template to cpp file
function AddTemplate(tmpl_file)
    exe "0read " . a:tmpl_file
    7
endfunction

autocmd BufNewFile *.cpp call AddTemplate("~/template.cpp")
"========== EOF =========="
