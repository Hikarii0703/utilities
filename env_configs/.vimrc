call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'cocopon/iceberg.vim'
call plug#end()

set termguicolors background=light t_Co=256 
syntax on
let g:lightline={'colorscheme': 'iceberg'}
colo iceberg

nnoremap j gj
nnoremap k gk
nnoremap n nzz
nnoremap N Nzz
set hlsearch incsearch ignorecase smartcase

set shiftround shiftwidth=4 tabstop=4 expandtab softtabstop=4
autocmd FileType html setlocal shiftwidth=2 tabstop=2 softtabstop=2
set autoindent smartindent cino=j1,(0,ws,Ws,L0
set foldmethod=syntax nofoldenable foldlevel=99 
set laststatus=2 noshowmode encoding=utf-8 showcmd nu rnu nobackup noswapfile nowrap
set ttimeout ttimeoutlen=0

set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

autocmd FileType cpp setlocal commentstring=//\ %s

map <leader>fm :%!astyle --mode=c --style=google -xV -H -y -j -xf -p -xg -U -W3<CR>
map <F3> :%y+<CR>
map <F9> :w <bar> !cpcompile "%:t"<CR>
map <F10> :!cprun_test "%:t"<CR>
map <F8> :!cprun "%:t"<CR>
nnoremap <Leader>ve :e $MYVIMRC<CR>
nnoremap <Leader>vr :source $MYVIMRC<CR>
nnoremap <F5> :let _s=@/<Bar>:%s/\s\+$//e<Bar>:let @/=_s<Bar><CR>
noremap <silent> <leader><cr> :noh<cr>
