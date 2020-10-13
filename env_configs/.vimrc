"========== Plugins =========="
call plug#begin('~/.vim/plugged')

Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdcommenter'
Plug 'SirVer/ultisnips'
Plug 'lifepillar/vim-solarized8'

call plug#end()
"========== Colorcheme =========="
set termguicolors background=light t_Co=256 
syntax on
let g:lightline={'colorscheme': 'solarized'}
colorscheme solarized8
"========== Settings =========="
nnoremap j gj
nnoremap k gk

set hlsearch
set incsearch
set ignorecase
set smartcase
nnoremap n nzz
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap g* g*zz
nnoremap g# g#zz
noremap <silent> <leader><cr> :noh<cr>
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

filetype plugin indent on
set shiftround shiftwidth=4 tabstop=4 expandtab softtabstop=4 cinoptions+=L0
set autoindent smartindent cindent

set laststatus=2 noshowmode number encoding=utf-8 showcmd

augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

set nobackup noswapfile

let g:NERDSpaceDelims = 1
map <C-c> <leader>cb
map <C-x> <leader>cu

map <leader>fm :%!astyle --mode=c --style=google -xV -H -y -j -xf<CR>
"========== CP config =========="
map <F3> :%y+<CR>
map <F9> :w <bar> !contest "%:t"<CR>
map <F10> :!run_test "%:t"<CR>
map <F8> :!run_contest "%:t"<CR>
"========== EOF =========="
